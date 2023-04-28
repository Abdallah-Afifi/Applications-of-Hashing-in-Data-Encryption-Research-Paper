Background Information

As the volume of data on the internet continues to grow exponentially, the need for efficient storage, access, and processing of this information becomes increasingly critical. Traditional data structures, such as arrays, provide a means for data storage, but their search time complexity of O(log n) can result in significant inefficiencies for large datasets. To address this challenge, the hashing data structure was developed, which allows for constant-time storage and retrieval of data (O(1)) in the best-case scenario. This is because knowing how a key was stored makes it easier to find it again without traversing through many elements, contrary to an array. You can find its position simply by applying the same algorithm that was used to store it in the first place, making it a more efficient data structure for heavy search, deletion, and insertion applications in comparison to a traditional array. 

The core components of hashing include the key, hash function, and hash table. The key, typically a string or integer, serves as input to the hash function. A hash function generates a unique index, or hash index, for storage in the hash table. It is a mathematical formula that calculates the index where the key will be stored in the hash table. The result of the hash function is called the hash value. This specialized data structure enables the efficient mapping of keys to values, facilitating a wide range of encryption applications that demand fast and secure data storage and retrieval.



What are collisions? This is a problem with hashing where different keys result in the same hash value when passed to the hash function. There are multiple solutions to this problem.

When it is important to ensure that multiple keys can have the same hash value, we use closed addressing, or open hashing. These implementations involve an array of pointers to a linked list, where the pointers in the array point to integer values representing the hash values, and the connected linked list has nodes with the same hash value. This implementation has a relatively higher search complexity for especially if many of the keys have the same hash value.

When it is not important to ensure that the keys have the same hash value, we use open addressing, or closed hashing. This method has 3 different implementations: Linear probing, quadratic probing, and double hashing. In this type of hashing, when a hash value is calculated and an attempt to insert the key at its hash index fails because it is already occupied, one of these methods is used to find the next closest empty slot for the key. Linear probing Linear probing is a collision resolution technique used in open addressing-based hash tables. In a hash table, when two or more keys produce the same hash index (known as a collision), it is necessary to find an alternative location to store the incoming key-value pair. Linear probing addresses this issue by searching for the next available slot in the hash table in a sequential manner.

The linear probing process works as follows:

When a collision occurs, the algorithm starts at the original hash index and moves forward (wrapping around if necessary) through the hash table one position at a time.
The algorithm checks each slot in the hash table to see if it is empty or not.
If an empty slot is found, it means that the key has not been inserted before, and the key-value pair is stored in that location.
If the algorithm reaches the original hash index after checking all slots, the hash table is considered full, and a resize or rehash operation may be required.
While linear probing is simple to implement and can provide good performance in low load scenarios, it can suffer from a drawback known as primary clustering, where large groups of consecutive occupied slots form, increasing the average search time. Alternative collision resolution techniques, such as quadratic probing and double hashing, can help mitigate this issue.

Quadratic probing is another collision resolution technique used in open addressing-based hash tables. Like linear probing, quadratic probing aims to find an alternative location for a key-value pair when a collision occurs. However, instead of searching for the next available slot in a linear manner, quadratic probing uses a quadratic function to determine the next probe location. This approach helps mitigate the primary clustering issue that can arise in linear probing.

The quadratic probing process works as follows:

When a collision occurs, the algorithm starts at the original hash index and applies a quadratic function to determine the next probe location. The function is typically of the form: newIndex = (originalIndex + c1 * i^2) % tableSize, where i is the probe number (starting at 1), and c1 is a constant value.
The algorithm checks the new index in the hash table to see if it is empty or not.
If an empty slot is found, the key-value pair is stored in that location.
If the slot is not empty, the probe number (i) is incremented, and the algorithm repeats steps 1-3 until an empty slot is found or all possible slots are checked.
If the algorithm checks all possible slots and no empty slot is found, the hash table is considered full, and a resize or rehash operation may be required.
Quadratic probing improves upon linear probing by reducing primary clustering, but it can still suffer from a different form of clustering called secondary clustering. To further address clustering issues, alternative techniques such as double hashing can be employed.

Double hashing is a collision resolution technique used in open addressing-based hash tables. It offers a more effective way to find alternative locations for key-value pairs when collisions occur, reducing both primary and secondary clustering issues that can arise in linear and quadratic probing.

In double hashing, two hash functions are used: the first one (h1) determines the initial index in the hash table, while the second one (h2) calculates the step size for probing. When a collision occurs, the algorithm combines these two hash functions to determine the next probe location.

The double hashing process works as follows:

When a collision occurs, the algorithm first computes the initial index using the primary hash function, h1(key).
Next, the step size is calculated using the secondary hash function, h2(key). It is important that h2(key) always returns a value greater than zero and is relatively prime to the table size to ensure that all slots can be probed.
The algorithm then checks the new index in the hash table, newIndex = (h1(key) + i * h2(key)) % tableSize, where i is the probe number (starting at 1).
If the new index is empty, the key-value pair is stored in that location.
If the slot is not empty, the probe number (i) is incremented, and the algorithm repeats steps 3-4 until an empty slot is found or all possible slots are checked.
If the algorithm checks all possible slots and no empty slot is found, the hash table is considered full, and a resize or rehash operation may be required.
Double hashing provides better performance compared to linear and quadratic probing, as it significantly reduces clustering effects. However, it requires the implementation of two hash functions and slightly higher computation overhead, which can be a trade-off to consider.

