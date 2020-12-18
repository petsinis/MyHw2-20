
public class A {

	public static void main(String[] args) {
		DoubleLinkedList2  double_link2;
	    DoubleLinkedList2  double_link3;
	    DoubleLinkedList2  double_link4;
	    
	    double_link2=new DoubleLinkedList2(0);
	    double_link3=new DoubleLinkedList2(0);
	    double_link4=new DoubleLinkedList2(0);
	    
	    
	    for(int i=1;i<150000000;i++) {	
	    	if(i%250==0.0) {
	    		double_link2.insertAtEnd(i);
	    	}
	    	else {
	    		double_link4.insertAtEnd(i);
	    	}
	    } 
	    double_link4=null;
	  
	    for(int i=1;i<160000000;i++) {	
	    	double_link3.insertAtEnd(i);
	    }
	    double_link3=null;
	    
	   
	    long start2 = System.nanoTime();    
	    double_link2.crossAll();
	    long elapsedTime2 = System.nanoTime() - start2;
	    System.out.println(elapsedTime2);
	    
	    
	    DoubleLinkedList2  double_link5;
	    double_link5=new DoubleLinkedList2(0);
	    for(int i=1;i<600000;i++) {	
	    	double_link5.insertAtEnd(i); 	
	    }
	    long start3 = System.nanoTime();    
	    double_link5.crossAll();
	    long elapsedTime3 = System.nanoTime() - start3;
	    System.out.println(elapsedTime3);

	}

}
