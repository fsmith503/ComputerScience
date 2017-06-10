
import java.util.Random;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;
public class Consumer implements Runnable {
	Random rand = new Random();
	private String name2;
	LinkedBlockingQueue<String> _queue = new LinkedBlockingQueue<String>();
	public Consumer(LinkedBlockingQueue<String> input_queue, String name) {
		_queue = input_queue;
		name2 = name;
	}
	@Override
	public void run() {
		int consumer_counter = 0;
		int counter = 0;
		while(_queue.size() >= 1 || Producer.in_progress == true){
		if(counter % 100 == 0 && counter != 0){
			System.out.println(name2 + ":" + " " + counter+ " " + "events consumed");
		}
		try{
			String temp = _queue.poll(rand.nextInt(10) + 1, TimeUnit.MILLISECONDS);
			if(temp != null){
				consumer_counter++;
			}
		}
		catch(InterruptedException e){
		}
		counter++;
		//consumer_counter ++;
		}
		System.out.println(name2 + " " + "consumes" + " " + consumer_counter + " " + "events.");
	}
}
