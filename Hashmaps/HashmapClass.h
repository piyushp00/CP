#include <string>

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
        numBuckets = 0;
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

private:
    //hash function
    int getBucketIndex(string key){
        int hashCode = 0;

        int currCoeff = 1;
        for(int i = key.length() - 1; i >=0; i--){
            hashCode += key[i] * currCoeff;
            hashCode = hashCode % numBuckets;
            currCoeff *= 37  //(let p = 37(prime no.))
            currCoeff = currCoeff % numBuckets; //to make sure coeff doesn't go out of range we will use modulus //! (n1 + n2 + n3) % r = ((n1 % r)*(n2 % r)*(n3 % r))
        }
        return hashCode % numBuckets;
    }

public:

    //insert fn
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(string key);
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
    } 

    //remove fn
    V remove(string key){
        int bucketIndex = getBucketIndex(string key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;

        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL; //for deleting memory
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; //signifies invalid value/not found
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(string key);
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