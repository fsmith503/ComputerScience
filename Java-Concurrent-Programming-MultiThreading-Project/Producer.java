import java.util.concurrent.LinkedBlockingQueue;

public class Producer implements Runnable{	
	static boolean in_progress = true;
	public String name1;
	 LinkedBlockingQueue<String> _queue = new LinkedBlockingQueue<String>();
	 public Producer(LinkedBlockingQueue<String> input_queue, String name) {
		_queue = input_queue;
		name1 = name;	
	}	
	@Override
	public void run(){
		int producer_counter = 0;
		for(int i = 0; i < 1000; i++){
			double k = Math.random();
			String l = Double.toString(k);
			if(i % 100 == 0 && _queue.size() != 0){
				System.out.println(name1 + ":" + " " + i + " " +  "events produced"); // error was printing the _queue.size()
			}
			try {
				_queue.put(l);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			producer_counter ++;
		}
		in_progress = false;
		System.out.println("Summary:");
		System.out.println(name1 + " " +  "produces" + " " + producer_counter + " " + "events.");
	}
}