
public class BST<E extends Comparable<E>> {
    private Node<E> root;

    public BST(){
        root = null;
    }

    // down and slow, focus
    public Node<E> getRoot(){
        return root;
    }

    public void insert(E data){

        // Find the right spot in the tree for the new node
        // Make sure to check if anything is in the tree
        // Hint: if a node n is null, calling n.getData() will cause an error
		Node<E> temp = new Node<E>(data);
		if(this.root == null)
			this.root = temp;
		else {
			Node<E> current = this.root;
			Node<E> parent = null;
			while(true) {
				parent = current;
				if (data.compareTo(parent.getData()) < 0) {
					current = current.getLeftChild();
					if(current == null) {
						parent.setLeftChild(temp);
						return;
					}
				} else {
					current = current.getRightChild();
					if(current == null) {
						parent.setRightChild(temp);
						return;
					}
				}
			}
		}
    }

    public Node<E> find(E data){

        // Search the tree for a node whose data field is equal to data
		Node<E> current = this.getRoot();
		while(true) {
			if(current == null)
				break;
			if(data.compareTo(current.getData()) == 0)
				return current;
			else if(data.compareTo(current.getData()) < 0)
				current = current.getLeftChild();
			else
				current = current.getRightChild();
		}
		return null;
    }

    public void delete(E data){
        // Find the right node to be deleted

        // If said node has no children, simply remove it by setting its parent to point to null instead of it.
        // If said node has one child, delete it by making its parent point to its child.
        // If said node has two children, then replace it with its successor,
        //          and remove the successor from its previous location in the tree.
        // The successor of a node is the left-most node in the node's right subtree.
        // If the value specified by delete does not exist in the tree, then the structure is left unchanged.

        // Hint: You may want to implement a findMin() method to find the successor when there are two children
    }

    public void traverse(String order, Node<E> top) {
        if (top != null){
            switch (order) {
                case "preorder":
                    // Your Code here
					System.out.print(top.getData() + " ");
					if(top.getLeftChild() != null)
						traverse("preorder", top.getLeftChild());
					if(top.getRightChild() != null)
						traverse("preorder", top.getRightChild());
                    break;
                case "inorder":
                    // Your Code here
					if(top.getLeftChild() != null)
						traverse("inorder", top.getLeftChild());
					System.out.print(top.getData() + " ");
					if(top.getRightChild() != null)
						traverse("inorder", top.getRightChild());
                    break;
                case "postorder":
                    // Your Code here
					if(top.getLeftChild() != null)
						traverse("postorder", top.getLeftChild());
					if(top.getRightChild() != null)
						traverse("postorder", top.getRightChild());
					System.out.print(top.getData() + " ");
                    break;
            }
        }
    }

    public Node<E> getMin(Node<E> top){
        // Return the min node
		Node<E> current = this.root;
		while(current.getLeftChild() != null) {
			Node<E> parent = current;
			current = current.getLeftChild();
			current.setParent(parent);
		}
		return current;
    }
}
