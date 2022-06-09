// Producer Consumer’s Problem without Synchronization the

import java.lang.Thread;

// Producer class which extends the
// thread
class Producer extends Thread {

	// Creating a string buffer
	StringBuffer buffer;

	// Initializing the string buffer
	Producer()
	{
		buffer = new StringBuffer(4);
	}

	// Overriding the run method
	public void run()
	{

		// Loop to add data into the
		// buffer
		for (int i = 0; i < 4; i++) {
			try {
				buffer.append(i);
				System.out.println("Produced " + i);
			}
			catch (Exception e) {

				// Exception is returned when
				// the buffer is not accessible
				e.printStackTrace();
			}
		}
		System.out.println("Buffer is FUll");

		// Creating a consumer object after
		// execution of the above method.
		// Here, this keyword refers to
		// the current object of the
		// producer. This object is passed
		// into the consumer to access the
		// created buffer
		Consumer c = new Consumer(this);
	}
}

// Consumer class which extends
// the thread
class Consumer extends Thread {
	Producer p;
	Thread t2;

	// Constructor to get the
	// producer object
	Consumer(Producer temp)
	{
		p = temp;

		// Creating a new thread for
		// the object
		t2 = new Thread(this);
		t2.start();
	}

	// Overriding the run method
	public void run()
	{
		try {

			// Printing the string buffer and
			// consuming it
			for (int i = 0; i < 4; i++) {
				System.out.print(p.buffer.charAt(i) + " ");
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("\nBuffer is Empty");
	}
}

// Main class to implement the
// Producer Consumer problem
class Efficiency {
	public static void main(String args[])
	{
		// Producer object is created and
		// passed into the thread.
		Producer p = new Producer();
		Thread t1 = new Thread(p);

		// Here, instead of the same
		// thread waiting, a new thread
		// is created in the constructor
		// of the consumer class
		t1.start();
	}
}
