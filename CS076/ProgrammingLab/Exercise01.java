public class Exercise01 {
    // Dear Student,
    // Write your own version of a class template that will create a binary
    // tree that can hold values of any class type.
    // Test your program class with a driver program.

    // write a private static class template TreeNode for comparable parameter type
    // T
    private static class TreeNode<T extends Comparable<T>> {

        private T value;
        private TreeNode<T> left;
        private TreeNode<T> right;

        public TreeNode(T value) {
            this.value = value;
        }

        public T getValue() {
            return value;
        }

        public void setValue(T value) {
            this.value = value;
        }

        public TreeNode<T> getLeft() {
            return left;
        }

        public void setLeft(TreeNode<T> left) {
            this.left = left;
        }

        public TreeNode<T> getRight() {
            return right;
        }

        public void setRight(TreeNode<T> right) {
            this.right = right;
        }

    }

    // Write a private class template BinaryTree for comparable parameter type T
    private static class BinaryTree<T extends Comparable<T>> {

        private TreeNode<T> root;

        public void insertNode(T value) {
            if (root == null) {
                root = new TreeNode<>(value);
            } else {
                insertRecursively(root, value);
            }
        }

        // searchNode
        public boolean searchNode(T value) {
            return searchRecursively(root, value);
        }

        // remove method
        public void remove(T value) {
            root = removeRecursively(root, value);
        }

        // displayInOrder method
        public void displayInOrder() {
            displayInOrderRecursively(root);
        }

        // displayPreOrder method
        public void displayPreOrder() {
            displayPreOrderRecursively(root);
        }

        // displayPostOrder method
        public void displayPostOrder() {
            displayPostOrderRecursively(root);
        }

        // private methods

        // insertRecursively method
        private void insertRecursively(TreeNode<T> currentNode, T value) {
            if (value.compareTo(currentNode.getValue()) < 0) {
                if (currentNode.getLeft() == null) {
                    currentNode.setLeft(new TreeNode<>(value));
                } else {
                    insertRecursively(currentNode.getLeft(), value);
                }
            } else {
                if (currentNode.getRight() == null) {
                    currentNode.setRight(new TreeNode<>(value));
                } else {
                    insertRecursively(currentNode.getRight(), value);
                }
            }
        }

        // searchRecursively
        private boolean searchRecursively(TreeNode<T> currentNode, T value) {
            if (currentNode == null) {
                return false;
            }
            if (value.compareTo(currentNode.getValue()) == 0) {
                return true;
            }
            return value.compareTo(currentNode.getValue()) < 0
                    ? searchRecursively(currentNode.getLeft(), value)
                    : searchRecursively(currentNode.getRight(), value);
        }

        // removeRecursively method
        private TreeNode<T> removeRecursively(TreeNode<T> currentNode, T value) {
            if (currentNode == null) {
                return null;
            }
            if (value.compareTo(currentNode.getValue()) < 0) {
                currentNode.setLeft(removeRecursively(currentNode.getLeft(), value));
            } else if (value.compareTo(currentNode.getValue()) > 0) {
                currentNode.setRight(removeRecursively(currentNode.getRight(), value));
            } else {
                // handle the case where the value matches the currentNode value
                if (currentNode.getLeft() == null) {
                    return currentNode.getRight();
                } else if (currentNode.getRight() == null) {
                    return currentNode.getLeft();
                } else {
                    // Need to find the minimum value in the right subtree
                    currentNode.setValue(findMinValue(currentNode.getRight()));
                    currentNode.setRight(removeRecursively(currentNode.getRight(), currentNode.getValue()));
                }
            }
            return currentNode;
        }

        // findMinValue method
        private T findMinValue(TreeNode<T> currentNode) {
            return currentNode.getLeft() == null ? currentNode.getValue() : findMinValue(currentNode.getLeft());
        }

        // private displayInOrderRecursively method
        private void displayInOrderRecursively(TreeNode<T> node) {
            if (node != null) {
                displayInOrderRecursively(node.getLeft());
                System.out.print(node.getValue() + " ");
                displayInOrderRecursively(node.getRight());
            }
        }

        // private displayPreOrderRecursively method
        private void displayPreOrderRecursively(TreeNode<T> node) {
            if (node != null) {
                System.out.print(node.getValue() + " ");
                displayPreOrderRecursively(node.getLeft());
                displayPreOrderRecursively(node.getRight());
            }
        }

        // private displayPostOrderRecursively method
        private void displayPostOrderRecursively(TreeNode<T> node) {
            if (node != null) {
                displayPostOrderRecursively(node.getLeft());
                displayPostOrderRecursively(node.getRight());
                System.out.print(node.getValue() + " ");
            }
        }

    }

    // Write main function to test BinnaryTree class here
    public static void main(String[] args) {
        // create a binary tree
        BinaryTree<Integer> binaryTree = new BinaryTree<>();
        // declare static dataValues
        int[] dataValues = { 5, 8, 3, 12, 9, 5};
        // insert dataValues into binary tree using for loop
        for (int dataValue : dataValues) {
            // print value inserted into the tree
            System.out.println("Inserting " + dataValue + " into the tree");
            binaryTree.insertNode(dataValue);
        }
        // display in order
        System.out.println("In order: ");
        binaryTree.displayInOrder();
        System.out.println();
        // display pre order
        System.out.println("Pre order: ");
        binaryTree.displayPreOrder();
        System.out.println();
        // display post order
        System.out.println("Post order: ");
        binaryTree.displayPostOrder();
        System.out.println();

        // test remove 5, we should have 1 5 left in the tree
        System.out.println("Deleting 5 from the tree");
        binaryTree.remove(5);
        System.out.println("In order: ");
        binaryTree.displayInOrder();
        System.out.println();
        

        // test delete method
        System.out.println("Deleting 8 from the tree");
        binaryTree.remove(8);
        System.out.println("In order: ");
        binaryTree.displayInOrder();
        System.out.println();
        // test search method
        System.out.println("Searching 12 in the tree");
        System.out.println(binaryTree.searchNode(12));
        System.out.println("Searching 8 in the tree");
        System.out.println(binaryTree.searchNode(8));

 
    }

}
