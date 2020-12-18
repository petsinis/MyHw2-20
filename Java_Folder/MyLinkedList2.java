public class MyLinkedList2 {
	 
	int number;
	MyLinkedList2 left;
	MyLinkedList2 right;
	
	public MyLinkedList2(int number) {
		this.number=number;
		left=null;
		right=null;
	}
	
	public void setNumber(int number) {
		this.number=number;
	}
	
	public void setLeft(MyLinkedList2 left) {
		this.left=left;
	}
	
	public void setRight(MyLinkedList2 right) {
		this.right=right;
	}
	
	public int getNumber() {
		return(number);
	}
	
	public MyLinkedList2 getLeft() {
		return(left);		
	}
	
	public MyLinkedList2 getRight() {
		return(right);		
	}
	
}
