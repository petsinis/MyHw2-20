
public class ParallelThreads {

	public static void main(String[] args) {
	    DoubleLinkedList2  double_link2;
	    double_link2=new DoubleLinkedList2(0);
	    long start3 = System.nanoTime();   
	    for(int i=1;i<170000000;i++) {
	    	double_link2.insertAtEnd(i);
	    }
	    long elapsedTime3 = System.nanoTime()- start3;
	    System.out.println(elapsedTime3);

	   	    
	    long start1 = System.nanoTime();    	    
	    for(int i=0;i<100000000;i++) {
				DoubleLinkedList2 double_link4;
				double_link4=new DoubleLinkedList2(0);
		    	for(int j=1;j<34;j++) {
		    		double_link4.insertAtEnd(j);
		    	}
		  }
	    long elapsedTime = System.nanoTime() - start1;
	    System.out.println(elapsedTime);
	    System.out.println(double_link2.countAll());

	}

}
