
Thr.currentThread().getId() ==== it gets the id of current thread

sleep(X) ==== method used to pause the execution of current thread for specified time in milliseconds

join() ===== method will put the current thread on wait until the thread on which it is called is dead
If thread is interrupted then it will throw InterruptedException


start() ===== method used to begin the execution of thread. The result of this method is two threads that are running concurrently


run() ====== method called if the thread was constructed using a separate Runnable object otherwise this method does nothing and returns



