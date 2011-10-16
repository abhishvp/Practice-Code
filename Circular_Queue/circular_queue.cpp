//compile as g++ -lpthread abhishcq.cpp


//#include <stdio.h>
//#include<stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>


#define ERROR_VAL -1
#define SUCCESS	-2
#define FLOAT_SZ sizeof(float)

class CircQueue {

public:
	int initialize(int maxSize);
	int enqueue(int element);
	int dequeue();

private:
	pthread_rwlock_t* rwlock ;	// Read/Write lock
	pthread_rwlockattr_t attr;	

	int* queueArray;
	int currQueueSize;
	int maxQueueSize;
	int frontIndex;
	int backIndex;
};

int CircQueue::initialize(int maxSize) {
	//Allow initialization only once	
	if(!queueArray) {

    	int fd = open("/tmp/lockfile", O_CREAT | O_TRUNC | O_RDWR, 0666);
    	ftruncate(fd, FLOAT_SZ);
    	void* ptr = mmap(NULL, FLOAT_SZ, PROT_READ | PROT_WRITE, 
							MAP_SHARED, fd,
        	             	0);
    	rwlock = (pthread_rwlock_t*)ptr;
    	pthread_rwlockattr_t attr;
    	pthread_rwlockattr_init(&attr);

		maxQueueSize = maxSize;
		queueArray = new int[maxQueueSize];
		currQueueSize = frontIndex = backIndex = 0;
		return SUCCESS;
	}

	return ERROR_VAL;
}

int CircQueue::enqueue(int element) {

	pthread_rwlock_rdlock(rwlock);

	//Allow adding when array is not full
	if(currQueueSize != maxQueueSize){

		pthread_rwlock_unlock(rwlock);
		pthread_rwlock_wrlock(rwlock);

		queueArray[backIndex] = element;
		++currQueueSize;
		backIndex = (backIndex+1) % maxQueueSize;

		pthread_rwlock_unlock(rwlock);

		return SUCCESS;
	}

	pthread_rwlock_unlock(rwlock);
	return ERROR_VAL;
}

int CircQueue::dequeue(){

	pthread_rwlock_rdlock(rwlock);
	//Allow only if queue is not empty
	if(currQueueSize != 0){
		pthread_rwlock_unlock(rwlock);
		pthread_rwlock_wrlock(rwlock);

		int tmpElem = queueArray[frontIndex];
		frontIndex = (frontIndex+1) % maxQueueSize;
		--currQueueSize;

		pthread_rwlock_unlock(rwlock);

		return tmpElem;
	}

	pthread_rwlock_unlock(rwlock);
	return ERROR_VAL; 
}


int main(){
	CircQueue* myCircQueue = new CircQueue();
	myCircQueue->initialize(5);
/*
	printf("\n%d\n", myCircQueue->enqueue(10));
	printf("\n%d\n", myCircQueue->enqueue(20));
	printf("\n%d\n", myCircQueue->enqueue(30));
	printf("\n%d\n", myCircQueue->enqueue(40));
	printf("\n%d\n", myCircQueue->enqueue(50));
	printf("\n%d\n", myCircQueue->dequeue());
	printf("\n%d\n", myCircQueue->enqueue(60));
	printf("\n%d\n", myCircQueue->dequeue());
	printf("\n%d\n", myCircQueue->enqueue(70));
	printf("\n%d\n", myCircQueue->enqueue(80));
	printf("\n%d\n", myCircQueue->enqueue(90));
*/
	return 1;

}
