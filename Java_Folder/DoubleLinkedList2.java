public class DoubleLinkedList2 {

	 MyLinkedList2 start;
	 MyLinkedList2 finish;
	
	public DoubleLinkedList2(int number) {
		MyLinkedList2 start_end=new MyLinkedList2(number);
		start=start_end;
		finish=start_end;
	}
	
	
	public boolean insertAtStart(int number) {
		MyLinkedList2 node=new MyLinkedList2(number);
		if(start==null) {
			return(false);
		}
		node.setRight(start);
		start.setLeft(node);
		start=node;
		return(true);
	}
	
	public boolean insertAtEnd(int number)
	{
	    MyLinkedList2 node=new MyLinkedList2(number);
	    if(finish==null){
	        return(false);
	    }
	    node.setLeft(finish);
	    finish.setRight(node);
	    finish=node;
	    return(true);
	}
	
	MyLinkedList2 searchFor(int number)
	{
	    if(start==null){
	        return(null);
	    }
	    MyLinkedList2 temp=start;
	    if(temp.getNumber()==number){
	        return temp;
	    }

	    while((temp.getRight())!=null){
	        temp=temp.getRight();
	        if(temp.getNumber()==number){
	            return temp;
	        }
	    }
	    return(null);
	}
	
	public boolean insertBefore(int number,int search_num)
	{
	    MyLinkedList2 temp=searchFor(search_num);
	    if(temp==null){
	        return(false);
	    }
	    MyLinkedList2 node=new MyLinkedList2(number);

	    node.setRight(temp);
	    if(temp!=start){
	        node.setLeft(temp.getLeft());
	        temp.getLeft().setRight(node);
	    }
	    else{
	        start=node;
	    }
	    temp.setLeft(node);
	    return(true);

	}
	
	
	public boolean insertAfter(int number,int search_num)
	{
	    MyLinkedList2 temp=searchFor(search_num);
	    if(temp==null){
	        return(false);
	    }
	    MyLinkedList2 node=new MyLinkedList2(number);

	    node.setLeft(temp);
	    if(temp!=finish){
	        node.setRight(temp.getRight());
	        temp.getRight().setLeft(node);
	    }
	    else{
	        finish=node;
	    }
	    temp.setRight(node);

	    return(true);

	}
	
	
	public boolean deleteStart()
	{
		if(start==null)
	    {
	        return(false);
	    }
	    if(start==finish){
	        return(true);
	    }
	     MyLinkedList2 temp=(start).getRight();


	     start=temp;
	     ((start)).setLeft(null);
	     return(true);
	}
	
	
	public boolean deleteNode(int number)
	{
	     MyLinkedList2 temp=searchFor(number);
	     if(temp==null)
	     {
	        return(false);
	     }
	     if(start==temp){
	        return(deleteStart());
	     }
	     if(start==finish){
	          return(deleteFinish());
	     }
	     MyLinkedList2 temp_left=temp.getLeft();
	     MyLinkedList2 temp_right=temp.getRight();

	     temp_left.setRight(temp_right);
	     temp_right.setLeft(temp_left);


	     return(true);

	}
	
	
	public boolean deleteFinish()
	{
		if(start==null)
	    {
	        return(false);
	    }
	    if(start==finish){
	        return(true);
	    }
	     MyLinkedList2 temp=(finish).getLeft();
	     finish=temp;
	     ((finish)).setRight(null);

	     return(true);
	}
	
	
	public MyLinkedList2 getStart()
	{
	    return(start);
	}

	public MyLinkedList2 getFinish()
	{
	    return(finish);

	}
	
	public void printAllStart()
	{
		System.out.println("mphke");
	    if(start==null){
	        return;
	    }
	    MyLinkedList2 temp=start;
	    System.out.print((temp).getNumber());
	    System.out.print(" ");
	    while((temp.getRight())!=null){
	    	//System.out.println("mphke");
	        temp=temp.getRight();
	        System.out.print(temp.getNumber());
	        System.out.print(" ");
	    }
	    System.out.println();
	}


	public void printAllEnd()
	{
	    if(finish==null){
	        return;
	    }
	    MyLinkedList2 temp=finish;
	    System.out.print((temp).getNumber());
	    System.out.print(" ");
	    while((temp.getLeft())!=null){
	        temp=temp.getLeft();
	        System.out.print(temp.getNumber());
	        System.out.print(" ");
	    }
	    System.out.println();
	}
	
	public void crossAll()
	{
	    if(start==null){
	        return;
	    }
	    MyLinkedList2 temp=start;
	    while((temp.getRight())!=null){
	        temp=temp.getRight();
	    }
	}
	
	public long countAll()
	{
		long count=0;
	    if(start==null){
	        return 0;
	    }
	    MyLinkedList2 temp=start;
	    count=1;
	    while((temp.getRight())!=null){
	        temp=temp.getRight();
	        count=count+1;
	    }
	    return count;
	}
	
	public void deletePerStep(int step,int r)
	{
		int count=0;
	    if(start==null){
	        return;
	    }
	    MyLinkedList2 temp=start;
	    MyLinkedList2 temp2=null;
	    while((temp.getRight())!=null){
	    	temp2=temp;
	        temp=temp.getRight();
	        count=count+1;
	        if(((count-1)%step)<=r) {
	        	//System.out.println(temp2.number);
	        	deletePointer(temp2);
	        }
	    }
	}
	
	public boolean deletePointer(MyLinkedList2 temp)
	{
	     if(temp==null)
	     {
	        return(false);
	     }
	     if(start==temp){
	        return(deleteStart());
	     }
	     if(start==finish){
	          return(deleteFinish());
	     }
	     MyLinkedList2 temp_left=temp.getLeft();
	     MyLinkedList2 temp_right=temp.getRight();
	     
	     temp=null;
	     
	     temp_left.setRight(temp_right);
	     temp_right.setLeft(temp_left);


	     return(true);

	}
	
}
