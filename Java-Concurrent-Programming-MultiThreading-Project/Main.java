/*
The goal of this assignment for me to gain experience working with concurrent 
programming via multiple threads and thread synchronization. I wrote
an implementation that simulates producer and consumer threads. The consumer
will take more time to complete than the producer, causing the machine to run
out of memory if threads are not synchronized in such a way that no more than 
a specified number of units are produced prior to being consumed.

I Created a new class with a public static void main method that creates
a java.util.concurrent.LinkedBlockingQueue with enough capacity for 100 String entries. 

I Created a new class which implements Runnable to simulate the producer.
When executed, a total of 1000 random Strings (e.g., using Math.random() and 
Double.toString()) are added to the above queue.The program needs to wait until there 
is space in the queue if necessary (i.e., using the LinkedBlockingQueue<T> put() method to add Strings). 
I Printed the progress (i.e., the total number of Strings added so far) once every 100 Strings added. 

I Created another new class which implements Runnable to simulate the consumer.
When executed, this thread consumes Strings from the queue. Consumption continues 
as long as there are Strings in the queue or the producer hasn't finished 
(i.e., the consumer doesn't quit if the queue happens to be empty before the producer finishes).
I Used the Thread sleep() method to wait up to 10 milliseconds 
(i.e., a random number of milliseconds on the range [0, 10)) before each String 
consumption to ensure that the consumer takes longer time to execute than the producer.
I Printed the progress once every 100 Strings consumed. 

I Implemented my program in such a way that it supports one producer and 
an arbitrary number of consumers. The consumers are expected to consume at different 
rates, so consumers should not simply consume a predetermined number of Strings 
and then quit; one consumer may complete significantly earlier than the others and
would be idle waiting for the others in this case. So I wanted a way for 
my producer to signal its completion to all the consumers (e.g., creating a Boolean 
variable shared by the producer and all the consumers); I also needed to ensure 
that I don't have a consumer potentially waiting indefinitely for a String to be
produced (e.g., using LinkedBlockingQueue<T> poll() method with a timeout). 

I Executed my program with 1 producer and at least 2 consumers concurrently.
My program  automatically quits after all 1000 Strings are produced and consumed.
Before quitting,  I printED the summarized information about how many Strings the producer 
produces and how many Strings each consumer consumes exactly. 
*/

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;

public class Main {
	public static void main(String[] args){
		 LinkedBlockingQueue<String> queue = new LinkedBlockingQueue<String>(100);
		ExecutorService executor = Executors.newCachedThreadPool();
			executor.submit(new Producer(queue, "Producer1"));
			executor.submit(new Consumer(queue, "Consumer1"));
			executor.submit(new Consumer(queue, "Consumer2"));
			executor.shutdown();	
	}
}
