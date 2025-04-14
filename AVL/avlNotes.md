## AVL Trees
- A variant of self-balancing binary search trees <br>
- A Balanced binary tree is a tree whose subtrees heights do not differ by more than one <br>
- Best way to keep a tree balanced? Balance the tree after every insertion/removal <br>
- AVL nodes are very similar to BST nodes except they hold more information such as their height and balance <br>
- AVL's are balanced via rebalancing operations, which occur when inserting or removing cause an excessive height difference <br><br>

## AVL Tree Properties
- The height of an AVL tree will always be **O(logn)** <br>
- Minimum number of nodes in an AVL tree can be found with the equation **N(h) = 1 + N(h-1) + N(h-2)** <br>
- AVL Trees will always be balanced after being operated on <br><br>

## Rotations
- The shape of the tree can be modifed via rotation operations <br>
- There is more than one tree that can contain the same values <br>
- A tree's shape can be altered and still preserve the BST property <br>

#### Left Rotation
- Rotate left node **n**:
- Take the left child of the right child of **n** and store it in a temp variable (temp)
- Make **n** the left child of its right child
- Take temp and make it the right child of **n**
- Update the parent node of **n** to point to **n**'s original right child

#### Right Rotation
- Rotate right node **n**:
- Take the right child of the left child of **n** and store it in a temp variable (temp)
- Make **n** the right child of its right child
- Take temp and make it the left child of **n**
- Update the parent node of **n** to point to **n**'s original left child

## Types of AVL Imbalances
Assume left imbalance == negative weight and right imbalance == positive weight <br>

#### Left-Left (LL)
- Current node has a negative weight and its left child also has a negative weight
- Solve with a single right rotation around the current node

#### Left-Right (LR)
- Current node has a negative weight and its left child has a postive weight
- Solve with a left rotation around the left child, then a right rotation around the current node
- After the first left rotation, the tree looks like the LL case

#### Right-Right (RR)
- Current node has a positive weight and its right child has a positive weight
- Solve with a left rotation around the current node

#### Right-Left (RL)
- Current node has a positive weight and its right child has a negative weight
- Solve with a right rotation around the right child, then follow with a left rotation around the current node
- After the first right rotation, the tree looks like the RR case


