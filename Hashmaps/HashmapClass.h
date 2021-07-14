#include <iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode *next;

    //Constructor
    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    //Destructor
    ~MapNode(){
        delete next;
    }
};

template <typename V>
class MyMap {
private:
    MapNode<V>** buckets;
    int count;
    int numBuckets;

public:
    //Constructor
    MyMap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++){
            buckets[i] = NULL;
        }
    }

    //Destructor
    ~MyMap(){
        for(int i = 0; i < numBuckets; i++){
            delete buckets[i];
        }
        delete[] buckets;
    }

    //size function
    int size(){
        return count;
    }

private:
    //!hash function
    int getBucketIndex(string key){
        int hashCode = 0;

        int currCoeff = 1;
        for(int i = key.length() - 1; i >=0; i--){
            hashCode += key[i] * currCoeff;
            hashCode = hashCode % numBuckets;
            currCoeff *= 37;  //(let p = 37(prime no.))
            currCoeff = currCoeff % numBuckets; //to make sure coeff doesn't go out of range we will use modulus //! (n1 + n2 + n3) % r = ((n1 % r)*(n2 % r)*(n3 % r))
        }
        return hashCode % numBuckets;
    }

    //! rehash function
    void rehash(){
        //point buckets to new array
        MapNode<V>** tempArr = buckets;
        buckets = new MapNode<V>*[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++){
            buckets[i] = NULL;
        }

        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        //for adding all data into new array of double size
        for(int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = tempArr[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value); //it will insert in empty one(with double size) bcz buckets is pointing to it.
                head = head->next;
            }
        }

        //delete temp array
        for(int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = tempArr[i];
            delete head;
        }
        delete[] tempArr;
    }

public:
    //! Load Factor
    double getLoadFactor(){
        return (1.0 * count)/numBuckets;
    }

    //insert fn
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        
        //!check load factor
        double loadFactor = (1.0 * count)/numBuckets; // (int/int) will give zero so multiply count by (1.0)
        if(loadFactor > 0.7){
            rehash();
        }
    } 

    //remove fn
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;

        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                V value = head->value; //save value before deleting memory
                head->next = NULL; //for deleting memory
                delete head;
                count--; //decrease total count after deleting
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; //signifies invalid value/not found
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0; //signifies not found
    }
};