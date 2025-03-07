#include <initializer_list>
#include <iostream>
#include <cassert>

/**********************************************************************************
 * README 
 * ********************************************************************************
 * This starter code is a skeleton of the Set and Node classes.
 * You can modify this code to create your project_5 submission.
 * Any main() function or output will be ignoed by testing software.
 * A testing main() can be found on Learn.
 * 
 * From Project 5 Specification: 2.1 Development Stratigies
 * "First, implement the node class and all of its member functions. This should be
 *  straight-forward from the course notes, as they are the sam member functions as 
 *  for a linked list.
 * 
 *  Second, start with a skeleton, where each member function is defined, but where
 *  the default values of the return type is returned. ..."
 * 
 * The skeleton has been povided (below) for you to modify.
*/

class Set;
class Node;
std::ostream &operator<<( std::ostream &out, Set const &rhs );
 
  /////////////////////////////
 /// Set class declaration ///
/////////////////////////////
class Set {
  public:
    Set( std::initializer_list<int> initial_values );
   ~Set();
 
    // The instructions will describe exactly what to do
    Set( Set const &orig );
    Set( Set      &&orig );
 
    // The instructions will describe exactly what to do
    Set &operator=( Set const &orig );
    Set &operator=( Set      &&orig );
 
    // Size operations
    bool        empty() const;
    std::size_t size()  const;
 
    // Clear all items out of the set
    void clear();
 
    // Find the value item in the set
    //  - Return the address of the node if found,
    //    and nullptr otherwise.
    Node *find( int const &item ) const;
 
    // Insert the item into the set if it
    // is not already in the set.
    //  - Return 1 if the item is new,
    //    and 0 otherwise.
    std::size_t insert( int const &item );
 
    // Insert all the items in the array
    // from array[begin] to array[end - 1]
    // that are not already in the set.
    //  - Return the number of items inserted
    //    into the set.
    std::size_t insert( int         const array[],
                        std::size_t const begin,
                        std::size_t const end );
 
    // Remove the item from the set and
    // return the number of items removed.
    std::size_t erase( int const &item );
 
    // Move any items from 'other', whose values
    // do not appear in 'this', to 'this'
    // Leave any items that already appear
    // in 'this' and 'other' in 'other'. 
    std::size_t merge( Set &other );

 
    // Set operations
    Set &operator|=( Set const &other );
    Set &operator&=( Set const &other );
    Set &operator^=( Set const &other );
    Set &operator-=( Set const &other );
 
    Set operator|( Set const &other ) const;
    Set operator&( Set const &other ) const;
    Set operator^( Set const &other ) const;
    Set operator-( Set const &other ) const;
 
    // Returns 'true' if the 'other' set
    // is a subset of 'this' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator<=( Set const &other ) const;
    bool operator>=( Set const &other ) const;
    bool operator<( Set const &other ) const;
    bool operator>( Set const &other ) const;
 
    bool operator==( Set const &other ) const;
    bool operator!=( Set const &other ) const;
    
  private:
    Node *p_head_;
 
  friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};


  ///////////////////////////////
 /// Node class declaration  ///
///////////////////////////////
class Node {
  public:
    Node( int new_value, Node *new_next ); //constructions
    int   value() const; //member function
    Node *next()  const; //
 // the function has access the the private values so we use the function so access the values. so any user can use the public. so they can use the publiuc to access the private. 
  //they can only see the values but not change them. Public functions have access to private value
  private:
    int   value_;
    Node *next_;

  // Allow any member function in the class
  // 'Set' to access or modify the member
  // variables of any instance of this class.
  friend class Set;
};

 
  ///////////////////////////////
 /// Node class Definition   ///
///////////////////////////////

// Node constructor
//tells it what to  with the values.
// definition for the constructor. depends what you pass as arguements
Node::Node( int new_value, Node *new_next ):
value_{new_value},
next_{new_next} { //BRUV NEXT is the pointer bruv.
// the function has access the the private values so we use the function so access the values. so any user can use the public. so they can use the publiuc to access the private. 
  //they can only see the values but not change them. Public functions have access to private value

}
 
int Node::value() const {
  return value_;
  //they can only see the values but not change them. Public functions have access to private value
}

Node *Node::next() const {
  return next_;
  //they can only see the values but not change them. Public functions have access to private value
}


  ///////////////////////////////
 /// Set class definition    ///
///////////////////////////////

// Initializing constructor
Set::Set( std::initializer_list<int> initial_values):
  p_head_{ nullptr } {
for ( int const &value : initial_values ) {
insert( value );
}
}


// Destructor
Set::~Set() {
    clear();  // Call clear() to remove all nodes and release allocated memory
}
 
// Copy constructor
Set::Set( Set const &orig ): p_head_{nullptr} {
   for (Node *ptr = orig.p_head_; ptr != nullptr; ptr = ptr->next_) {
        insert(ptr->value());  // Insert each value from the original set into the new set.
    }
}


// Move constructor
Set::Set(Set &&orig) 
    : p_head_{nullptr} {  
    std::swap(p_head_, orig.p_head_);  // Swap the pointers
}
 
// Copy assignment
Set &Set::operator=(Set const &orig) {
    if (this == &orig) {
        return *this;  
    } else {
    //Clear the current set
    clear();
    //Copy all elements from rhs to this.
    for (Node *ptr = orig.p_head_; ptr != nullptr; ptr = ptr->next_) {
        insert(ptr->value());  // Insert each value into the current set.
    }
    return *this;  // Return *this.
}
}

// Move assignment
Set &Set::operator=(Set &&orig) {
    if (this != &orig) {  // Check for self-assignment
        clear();  // Clean up the current object.

        // Transfer ownership of the linked list as given on the instructions for the doc.
        std::swap(p_head_, orig.p_head_);
    }
    return *this;  // Return the current object.
}
 
// Empty
bool Set::empty() const {
  if(p_head_ == nullptr){
 return true;
  } 
  return false;
}

// Size
size_t Set::size() const {
  std::size_t count = 0;  // Initialize count to zero.
    for (Node *ptr = p_head_; ptr != nullptr; ptr = ptr->next()) {
        ++count;  // Increment count for each node encountered during the loop.
    }
    return count;  // Return the total count.
    }
 
 
// Clear
void Set::clear() {
while (p_head_ != nullptr) {
        Node *temp = p_head_;  // Save the current head node as pointer to a temporary node.
        p_head_ = p_head_->next_;  // Move to the next node.
        delete temp;  // Delete the old head node.
    }
    p_head_ = nullptr;  // Ensure the head is null after clearing
}

 
// Find
Node *Set::find( int const &item ) const {
 Node *current {p_head_}; // Start from the head node
    while (current != nullptr) {
        if (current->value() == item) {
            return current; // Return the node if the value matches
        }
        current = current->next(); // Move to the next node
    }
  return nullptr;
}
 
// Insert the item into the set
std::size_t Set::insert( int const &item ) {
   // Check if the item already exists in the set
    if (find(item)) {
        return 0; // Item is already in the set, so no insertion is performed
    }
//else
    // Insert the new item at the head of the linked list
    p_head_ = new Node(item, p_head_);
    return 1; // One item has been inserted
}
 
// Insert all the items in the array
std::size_t Set::insert( int         const array[],
                         std::size_t const begin,
                         std::size_t const end ) {
 std::size_t count = 0;  // To count the number of successful insertions
     for (std::size_t i = begin; i < end; ++i) { //Use a for loop to iterate through the elements of the array from array[begin] to array[end - 1].
        count += insert(array[i]);  // Call insert for each item and add to count. Call the previously implemented insert(int const item) for each array element.
    }

    return count;  // Return the total number of items successfully inserted
}

// Remove the item from the set and
// return the number of items removed.
//IT'S JUST LIKE THE REMOVE we did w FORREST IKE. Same ting except we now have some random ting ike.
std::size_t Set::erase( int const &item ) { // we're trying to ERASE whatever item is. And item is a value enetered IN by the USER.
 //When deleting a node in a singly linked list, you cannot directly access the preceding node. previous allows us to reconnect the linked list by pointing the preceding node's next_ pointer to the node after the one being deleted.
 Node *current = p_head_; //current is initialized to point to the head of the linked list (p_head_). It acts as the pointer that traverses through the list, visiting each node one at a time.
    Node *previous = nullptr; // previous keeps track of the node that comes before current. It's essential when we need to update the next_ pointer of the preceding node to bypass (or "unlink") the node being deleted.  When deleting a node in a singly linked list, you cannot directly access the preceding node. previous allows you to reconnect the linked list by pointing the preceding node's next_ pointer to the node after the one being deleted.

    // Traverse the linked list to find the node containing the item. Move both pointers forward as you traverse: previous is set to the current node. current is updated to point to the next node (current->next_).
    while (current != nullptr) {
      //If current->value_ == item we want to remove, the node current is the one to be removed.
        if (current->value_ == item) {
             //If previous == nullptr, current is the head, so update p_head_.
            if (previous == nullptr) {
                p_head_ = current->next_;
            } else {
                // Removing a node that is not the head. Otherwise, update previous->next_ to skip the current node.
                previous->next_ = current->next_;
            }

            delete current;  // Deallocate memory for the node
            return 1;        // Return 1 as one item is removed
        }

        // Move to the next node
        previous = current;
        current = current->next_;
    }

    // If the item is not found, return 0
    return 0;
}
  
 
// Move any items from 'other', whose values
// do not appear in 'this', to 'this'.
// Leave any items that already appear
// in both sets, in both sets. 
std::size_t Set::merge( Set &other ) {
   std::size_t moved_count = 0;  // Keep track of the number of moved nodes

    Node *prev = nullptr;         // This pointer will hold the previous node to current as we traverse through the other set. It is set to nullptr initially because, at the start, there is no node before the first node (head) of other.
    Node *current = other.p_head_;  // This pointer represents the node that we are currently examining in other. We start with the first node in other (i.e., other.p_head_) and move through the list by advancing current to current->next_ at each step.

    while (current != nullptr) {
        //The find function is used to determine whether a particular value exists in the current set (this)
        if (find(current->value()) == nullptr) {
            //If find returns nullptr, it means the value is not already in the set (this). Therefore, the node needs to be moved from the other set to this set.
            Node *to_move = current;

            // Update pointers in the other set to remove the node
            if (prev == nullptr) {
                // Moving the head node pointer
                other.p_head_ = current->next_;
            } else {
                prev->next_ = current->next_;
            }

            // Move the node to this set and set it to the head.
            to_move->next_ = p_head_;
            p_head_ = to_move;

            // Increment the count of moved nodes
            moved_count++;

            // Advance the current pointer
           // We need to iterate through the nodes of the other set. This if statement is the part of the logic that advances the current pointer, which is used to traverse the other set’s linked list.
            if (prev == nullptr) {
              //When prev == nullptr (current is the first node in other). We need to set current to other.p_head_ because current is already pointing to other.p_head_ when we start.
    current = other.p_head_;
} else { //When prev != nullptr (current is not the first node). We need to move current to the next node in the other list. So we set current to prev->next_.
    current = prev->next_;
}

        } else {
            // Node is already in this set, leave it in the other set
            prev = current;
            current = current->next_;
        }
    }

    return moved_count;
}

  //////////////////////
 /// Set operations ///
//////////////////////
// Union operation (|=)
Set& Set::operator|=(const Set &other) {
    // Go through the right-hand side set
    for (Node* ptr = other.p_head_; ptr != nullptr; ptr = ptr->next_) {
        // Insert the value from other into the current set (if not already present)
        if (!find(ptr->value())) {
            insert(ptr->value());
        }
    }
    return *this;
}
 
// Intersection operation (&=)
Set& Set::operator&=(const Set& other) {
    // Traverse the current set
    if(p_head_ == nullptr){
        return *this;
    }
     if( other.empty()){
        clear();
        return *this;
    }
    for (Node* ptr = p_head_; ptr != nullptr; ptr = ptr->next_) {
        // If the value is not in the rhs set, erase it from the current set
        if (!other.find(ptr->value())) {
            erase(ptr->value());
        }
    }
    return *this;
}
 
// Symmetric Difference operation (ˆ=)
Set& Set::operator^=(const Set& other) {
    // Traverse the right-hand side set
    for (Node* ptr = other.p_head_; ptr != nullptr; ptr = ptr->next_) {
        if (find(ptr->value())) {
            // If the value is found in this set, erase it.
            erase(ptr->value());
        } else {
            // Otherwise, insert the value into this set.
            insert(ptr->value());
        }
    }
    return *this;
}
 
// Set Minus operation (-=)
Set& Set::operator-=(const Set& other) {
    // Traverse the right-hand side set.
    for (Node* ptr = other.p_head_; ptr != nullptr; ptr = ptr->next_) {
        // If the value is found in this set, erase it.
        erase(ptr->value());
    }
    return *this;
}
 
// Union operation (|), binary operator
Set Set::operator|(const Set& other) const {
    // Create a temporary set 'tmp' which is a copy of the current set.
    Set tmp{*this};
    // Perform the union operation using the automatic assignment operator.
    tmp |= other;
    // Return the temporary set.
    return tmp;
}
 
// Intersection operation (&), binary operator
Set Set::operator&(const Set& other) const {
    // Create a temporary set 'tmp' which is a copy of the current set.
    Set tmp{*this};
    // Perform the intersection operation using the automatic assignment operator.
    tmp &= other;
    // Return the temporary set.
    return tmp;
}
 
// Symmetric Difference operation (^), binary operator
Set Set::operator^(const Set& other) const {
    // Create a temporary set 'tmp' which is a copy of the current set.
    Set tmp{*this};
    // Perform the symmetric difference operation using the automatic assignment operator.
    tmp ^= other;
    // Return the temporary set.
    return tmp;
}
 
// Set Minus operation (-), binary operator
Set Set::operator-(const Set& other) const {
    // Create a temporary set 'tmp' which is a copy of the current set.
    Set tmp{*this};
    // Perform the set minus operation using the automatic assignment operator.
    tmp -= other;
    // Return the temporary set.
    return tmp;
}
//We create a temporary set tmp as a copy of the current set (*this).
 

// Returns 'true' if the 'other' set
// is a subset of 'this' set; that is,
// all entries in the 'other' set are
// also in this set.
// Superset operator (>=)
bool Set::operator>=( Set const &other ) const {
   // Traverse the right-hand side set
    for (Node* ptr = other.p_head_; ptr != nullptr; ptr = ptr->next_) {
        // If any value in other is not found in this set, return false.
        if (!find(ptr->value())) {
            return false;
        }
    }
    // Else All items in other are in this set
    return true;
}
 
// Subset operator (<=)
bool Set::operator<=(const Set &other) const {
    // Return true if other is a superset of this set.
    return other >= *this;
}
 
// Strict superset operator (>)
bool Set::operator>(const Set &other) const {
    // Check if this set is a superset of other
    if (*this >= other) {
        // If sizes are equal, the sets are identical, so not a strict superset.
        return size() > other.size();
    }
    // Else Not a superset
    return false;
}
 
// Strict subset operator (<)
bool Set::operator<(const Set &other) const {
    // Return true if other is a strict superset of this set
    return other > *this;
}


 // Equality operator (==)
bool Set::operator==( Set const &other ) const {
      // A set is equal to another if it is a superset of the other and vice versa.
    return (*this >= other) && (other >= *this);
}
 
// Inequality operator (!=)
bool Set::operator!=(const Set &other ) const {
    // Return the negation of the equality operator.
    return !(*this == other);
}


  ////////////////////////////////////////////
 /// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
/// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
  out << "{";
  if ( !rhs.empty() ) {
    out << rhs.p_head_->value();   
    for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
      out << ", " << ptr->value();
    }
  }
  out << "}";
 
  return out;
}