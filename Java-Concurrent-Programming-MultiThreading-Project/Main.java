
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
//First GTF
//copy code over
//example 23.14 , 23.15 , 23.18 , 23.19
//make data structure thread safe
//limit buffer linked list size
//makes producers produce 1000 items collectively
//lets consumers know when producers are done

//Second GTF
// change every time you access linked blocking list
// pattern when access queue
// both consumers take from queue at once
// wrap put and take call in locking
// stays same except for try 