/*
 Create an empty map (i.e., one with no key/value pairs)
 Map::Map() {
 
 root = nullptr;
 }
 
 bool Map::empty() const
 {
 if (root == nullptr)
 return true;
 else
 return false;
 } // Return true if the map is empty, otherwise false.
 
 Map::Map(const Map &rhs) {
 if (rhs.root == nullptr) {
 root = nullptr;
 }
 else
 {
 Mapnode *p = rhs.root;
 copyHelper(root, p);
 }
 }
 
 Mapnode* Map::copyHelper(Mapnode* &thisroot, const Mapnode* rhs) {
 if (rhs == nullptr)
 {
 return nullptr; // If there's no Node to copy, return NULL.
 }
 else
 {
 // This needed to be dynamically
 thisroot = new Mapnode;
 thisroot->keys = rhs->keys; // Copies data from other node.
 thisroot->val = rhs->val;
 thisroot->left = copyHelper(thisroot->left, rhs->left); // Recursive call to left node.
 thisroot->right = copyHelper(thisroot->right, rhs->right); // Recursive call to right node.
 
 return thisroot;
 }
 }
 
 
 Map:: ~Map()
 {
 destroy_tree(root); // call destroy function
 }
 
 void Map::destroy_tre()
 {
 destroy_tree(root);
 }
 void Map::destroy_tree(Mapnode *leaf) // take one node in parameter
 {
 if (leaf != NULL)
 {
 destroy_tree(leaf->left); // Use two recursive method, and one argument node points left another one points right
 destroy_tree(leaf->right);
 delete leaf;
 } // delete node
 }
 
 int Map::size() const
 {
 Mapnode*p = root;
 
 return size(p); // return auxiliary function.
 }
 int Map::size(Mapnode *p) const
 {
 if (p == NULL)  // if argument pointer is empty, return 0
 {
 return(0);
 }
 else // else return recursive function(node points left) + 1 and recursive function(node points points)
 {
 return (size(p->left) + 1 + size(p->right));
 }
 }
 
 void Map::insert_auxl(Mapnode *p, const KeyType &key, const ValueType &valu) {
 
 if (key < p->keys)
 {
 if (p->left != NULL)
 insert_auxl(p->left, key, valu);
 else
 {
 p->left = new Mapnode;
 p->left->keys = key;
 p->left->val = valu;
 p->left->left = NULL;    //Sets the left child of the child node to null
 p->left->right = NULL;   //Sets the right child of the child node to null
 }
 }
 else if (key >= p->keys)
 {
 if (p->right != NULL)
 insert_auxl( p->right, key, valu);
 else
 {
 p->right = new Mapnode;
 p->right->keys = key;
 p->right->val = valu;
 p->right->left = NULL;  //Sets the left child of the child node to null
 p->right->right = NULL; //Sets the right child of the child node to null
 }
 }
 
 }
 
 bool Map::insert(const KeyType& key, const ValueType& value)
 {
 if (root != NULL) {
 insert_auxl(root, key, value); //If the root is not null, it takes root, key and value. return true
 return true;
 }
 else {
 root = new Mapnode; // initialize the root
 root->keys = key; // Assign input key to root's key
 root->val = value; // Assign input value to root's value
 root->left = NULL; // root left = null
 root->right = NULL; // root right = null
 return false; // return false
 }
 }
 
 // If key is not equal to any key pently in the map, and if the
 // key/value pair can be added to the map, then do so and return true.
 // Otherwise, make no change to the map and return false (indicating
 // that either the key is already in the map).
 
 Mapnode* Map::update_auxl(Mapnode *&p, const KeyType& key)    const
 {
 if (p != nullptr)  //if it finds pointer's key, return pointer p.
 {
 if (key == p->keys) {
 return p;
 }
 else if (key < p->keys) { //if argument key is greater than pointer p keys, p points left. And use recursive method.
 return update_auxl(p->left, key);
 }
 else {                    //else, p points right. And use recursive method.
 return update_auxl(p->right, key);
 }
 }
 else {
 return nullptr;
 }
 }
 
 bool Map::update(const KeyType& key, const ValueType& value)
 {
 Mapnode *p;
 if (root != nullptr)    // if root is not null, p take root pointer.
 {
 p = update_auxl(root, key); // call auxiliary function
 p->val = value;
 return true; // return true
 }
 else
 cerr << "We couldn't find key" << key << endl; // if root is empty, it returns false.
 return false;
 }
 
 // If key is equal to a key pently in the map, then make that key no
 // longer map to the value it pently maps to, but instead map to
 // the value of the second parameter; return true in this case.
 // Otherwise, make no change to the map and return false.
 
 bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
 {//if update pointer is true, it returns true.
 if (update(key, value) == true)
 {
 return true;
 }
 
 cerr << "However it will insert new infromtion in node" << endl;
 return insert(key, value);
 
 
 
 }
 
 
 
 Mapnode * minValueMapNode(Mapnode* p)
 {
 Mapnode* min_val = p;
 
 
 while (min_val->left != NULL)
 min_val = min_val->left;
 
 return min_val;
 }
 
 Mapnode* Map::erase_auxl(Mapnode *p, const KeyType& key)
 {
 if (p == nullptr)
 {
 return p;}
 // If the key to be deleted is smaller than the root's key,
 // then it lies in left subtree
 if (key < p->keys)
 p->left = erase_auxl(p->left, key);
 
 // If the key to be deleted is greater than the root's key,
 // then it lies in right subtree
 else if (key > p->keys)
 p->right = erase_auxl(p->right, key);
 
 // if key is same as root's key, then This is the node
 // to be deleted
 else
 {
 // node with only one child or no child
 if (p->left == NULL)
 {
 Mapnode *temp = p->right;
 delete p;
 return temp;
 }
 else if (p->right == NULL)
 {
 Mapnode *temp = p->left;
 delete p;
 return temp;
 }
 
 // node with two children: Get the inorder successor (smallest
 // in the right subtree)
 Mapnode* temp = minValueMapNode(p->right);
 
 // Copy the inorder successor's content to this node
 p->keys = temp->keys;
 // Delete the inorder successor
 p->right = erase_auxl(p->right, temp->keys);
 }
 return p;
 }
 // If key is equal to a key pently in the map, then make that key no
 // longer map to the value it pently maps to, but instead map to
 // the value of the second parameter; return true in this case.
 // If key is not equal to any key pently in the map then add it and
 // return true. In fact this function always returns true.
 bool Map::erase(const KeyType& key)
 {
 if (root == nullptr)
 {
 cerr << " This Tree is empty! " << endl;
 return false;
 }
 
 if (!contains(key))
 {
 cerr << "The tree has no '" << key << endl;
 return false;
 }
 
 root = erase_auxl(root, key);
 return true;
 }
 // If key is equal to a key pently in the map, remove the key/value
 // pair with that key from the map and return true.  Otherwise, make
 // no change to the map and return false.
 
 bool Map::contains(const KeyType& key) const
 {
 Mapnode *p = root;
 
 if (update_auxl(p, key) != nullptr) // if update ptr is nullptr, return true
 return true;
 else                               // return false
 return false;
 }
 // Return true if key is equal to a key pently in the map, otherwise
 // false.
 
 bool Map::get(const KeyType& key, ValueType& value) const
 {
 Mapnode *p;
 p = root;
 
 if (update_auxl(p, key) != nullptr)
 {
 p = update_auxl(p, key);
 value = p->val;
 return true;
 }
 else
 {
 return false;
 }
 }
 // If key is equal to a key pently in the map, set value to the
 // value in the map that that key maps to, and return true.  Otherwise,
 // make no change to the value parameter of this function and return
 // false.
 Mapnode* Map::get_auxl(int& target, Mapnode* p)const
 {
 //int i = 0;
 
 if (p != nullptr) {
 
 if (target == 0)
 {
 return p;
 }
 
 target--;
 
 Mapnode *new_p = get_auxl(target, p->left); //pointer leaf points left, repeat the function as a recursive function
 
 if (new_p != nullptr)
 {
 p = new_p;
 return p;
 }
 
 new_p = get_auxl(target, p->right); //pointer leaf points right, repeat the function as a recursive function
 
 if (new_p != nullptr)
 {
 p = new_p;
 return p;
 }
 
 }
 return nullptr;
 }
 bool Map::get(int i, KeyType& key, ValueType& value) const
 {
 Mapnode *p;
 if (size() <= i)
 {
 return false;
 }
 else
 {
 p = get_auxl(i, root);
 
 if (p != nullptr)
 {
 key = p->keys;
 value = p->val;
 return true;
 }
 else
 {
 return false;
 }
 }
 }
 // If 0 <= i < size(), copy into the key and value parameters the
 // key and value of one of the key/value pairs in the map and return
 // true.  Otherwise, leave the key and value parameters unchanged and
 // return false.  (See below for details about this function.)
 
 Map& Map:: operator= ( Map rhs)     // operator assignment function
 {
 rhs.swap(*this); //call swap function of  right side.
 return *this;
 }
 
 
 void Map::swap(Map& other)
 {
 Mapnode* p;
 p = other.root;   //it assigns object root to pointer p
 other.root = root; //it assigns root ptr to object root
 root = p;  //it assigns pointer p to root
 }
 
 void subtract(const Map& m1, const Map& m2, Map& result)
 {
 Map ma, mb;
 KeyType k = " "; // default key and value
 ValueType v = 0;
 ma = m1;
 mb = m2;
 for (int i = 0; i < ma.size(); i++) //Index i is counted untill size of object M1
 {
 ma.get(i, k, v); // get keys and value for each node of object m1
 
 if (!mb.get(k, v)) // Insert M1 key to the 'k'parameter of M2 get(k,v).
 result.insert(k, v);//if( m1 key != m2 key),  Result object take m1 key
 }
 
 };
 
 bool combine(const Map& m1, const Map& m2, Map& result)
 {
 Map ma, mb;
 KeyType k1 = " " ;
 ValueType t = 0, f = 1, v1 = 0, v2 = 0;
 ma = m1;
 mb = m2;
 subtract(ma, mb, result); // call subtract function in order to use result obj
 
 for (int i = 0; i < mb.size(); i++) // for loop get all m2's ky/val pairs
 {
 mb.get(i, k1, v1);  // get keys/val of m2
 if(ma.get(k1, v2) == true) // if m1's keys/val == m2's keys/val, f = 0 it means false. v2 prevent not to change mb's value
 f = 0;  // it takes false value
 
 else
 {
 result.insert(k1, v1); // insert values/keys of m2 to result obj.
 }
 }
 
 if (f == 0) return false; //if f==0 returns flase
 else
 return true;
 }
 
 
 void Map::dump() const
 {
 Mapnode *temp = root;
 
 cerr << " \n inorder print " << endl;
 inorder_print(temp);
 cerr << " \n post order print " << endl;
 postorder_print(temp);
 exit(0);
 
 }
 void Map::postorder_print(Mapnode *leaf) const
 {
 if (leaf != NULL) {
 inorder_print(leaf->left);  //pointer leaf points left, repeat the function as a recursive function
 inorder_print(leaf->right); //pointer leaf points right, repeat the function as a recursive function
 cerr << leaf->val << ",";
 cerr << leaf->keys << "  ,";
 }
 }
 void Map::inorder_print(Mapnode  *leaf) const
 {
 if (leaf != NULL) {
 inorder_print(leaf->left); //pointer leaf points left, repeat the function as a recursive function
 cerr << leaf->val << ",";
 cerr << leaf->keys << "  ,";
 inorder_print(leaf->right); //pointer leaf points right, repeat the function as a recursive function
 }
 }
 
 int main() {
 //Map tree;
 Map pp; //class object for 'p' pointer
 Map ww, *a; //class object for 'w' pointer
 Map *p = new Map();
 Map *w = new Map();
 
 KeyType b = "a";
 ValueType vval = 181;
 
 cerr << "start !!" << endl;
 w->insert("b", 3);    //insert function
 w->insert("c", 2);
 w->insert("a", 1);
 w->insert("d", 2);
 w->insert("e", 1);
 
 w->erase("d");
 
 w->size();
 cerr << " size " << w->size() << endl;
 
 w->update("a", 11);
 w->get(b, vval);
 w->get(2, b, vval);
 
 p->insert("z", 9);
 p->insert("x", 10);
 p->insert("y", 12);
 p->insert("w", 13);
 
 //pp = *p; // pp object take p pointer
 //pp.swap(*w);// pp -> w =  w pointer
 //cerr << "swaped p to w, w pointer is " << endl;
 
 w->dump();
 
 }  */
