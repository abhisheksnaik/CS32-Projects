// MyHash.h

// Skeleton for the MyHash class template.  You must implement the first seven
// member functions; we have implemented the eighth.

//using namespace std;


template <typename KeyType, typename ValueType>
struct Node
{
    KeyType pairKey;
    ValueType pairValue;
    Node* next;
    Node* prev;
};



unsigned int hash(const int& i);

unsigned int hash(const char& c);



template<typename KeyType, typename ValueType>
class MyHash
{
public:
    MyHash(double maxLoadFactor = 0.5)
    {
        m_size = 4;
        m_table = new LinkedList[m_size];
        if(maxLoadFactor <= 0)
            m_load = 0.5;
        if(maxLoadFactor > 2)
            m_load = 2;
        m_load = maxLoadFactor;
        m_numItems = 0;
    }
    ~MyHash()
    {
        delete [] m_table;
    }
    void reset()
    {
        delete [] m_table;
        m_table = new LinkedList[100];
        m_size = 100;
    }
    void associate(const KeyType& key, const ValueType& value)
    {
        int keyLoc = (getBucketNumber(key) % m_size);
        /*Node<KeyType, ValueType>* n = m_table[keyLoc].first();
        while(n!=nullptr)
        {
            if(key == n->pairKey)
            {
                n->pairValue = value;
                break;
            }
            n = n->next;
        }
        if(n == nullptr)
        {
            m_table[keyLoc].addToRear(key, value);
            m_numItems++;
        }
        */
        
        if(m_table[keyLoc].findItem(key))
            m_table[keyLoc].updateList(key, value);
        else
        {
            m_table[keyLoc].addToRear(key, value);
            m_numItems++;
        }
        
        //int loadFactor = (m_numItems) / m_size;
        if(getLoadFactor() > m_load)
        {
            int newSize = m_size * 2;
            LinkedList* temp = new LinkedList[newSize];
            for(int i = 0; i < m_size; i++)
            {
                Node<KeyType, ValueType>* p = m_table[i].first();
                while(p!=nullptr)
                {
                    KeyType tempKey = p->pairKey;
                    ValueType tempVal = p->pairValue;
                    int tempLoc = getBucketNumber(tempKey) % newSize;
                    temp[tempLoc].addToRear(tempKey,tempVal);
                    p = p->next;
                }
            }
            m_table = temp;
            m_size = newSize;
            delete []temp;
        }
        
    }
    int getNumItems() const
    {
        return m_numItems;
    }
    double getLoadFactor() const
    {
        return ((double)(m_numItems/m_size));
    }
    
    // for a map that can't be modified, return a pointer to const ValueType
    const ValueType* find(const KeyType& key) const
    {
        if(m_table[getBucketNumber(key) % m_size].findItem(key))
        {
            ValueType value;
            m_table[getBucketNumber(key) % m_size].getValue(key, value);
            ValueType* ptr = &value;
            return ptr;
        }
        else
            return nullptr;
    }
    
    unsigned int getBucketNumber(const KeyType key) const
    {
        unsigned int hash(const	KeyType& k);
        unsigned int h = hash(key);
        return h;
    }
    
    
    // for a modifiable map, return a pointer to modifiable ValueType
    ValueType* find(const KeyType& key)
    {
        return const_cast<ValueType*>(const_cast<const MyHash*>(this)->find(key));
    }
    
    // C++11 syntax for preventing copying and assignment
    MyHash(const MyHash&) = delete;
    MyHash& operator=(const MyHash&) = delete;
    
private:
    class LinkedList
    {
    public:
        LinkedList()
        {
            head = nullptr;
            //tail = nullptr;
            m_nodeCounter = 0;
        }
        void addToFront(KeyType key, ValueType val)
        {
            Node<KeyType, ValueType>* n = new Node<KeyType, ValueType>;
            n->pairKey = key;
            n->pairValue = val;
            
            if(head == nullptr)
            {
                n->next = head;
                head = n;
                n->prev = nullptr;
            }
            else
            {
                n->next = head;
                head = n;
                n->prev = nullptr;
                n->next->prev = n;
                
            }
            
        }
        Node<KeyType, ValueType>* first()
        {
            return head;
        }
        
        void addToRear(KeyType k, ValueType v)
        {
            if(head == nullptr)
                addToFront(k, v);
            else
            {
                Node<KeyType, ValueType>* p;
                p = head;
                while(p->next!=nullptr)
                {
                    p = p->next;
                }
                Node<KeyType, ValueType>* n = new Node<KeyType, ValueType>;
                
                n->pairKey = k;
                n->pairValue = v;
                
                n->prev = p;
                n->next = nullptr;
                
                p->next = n;
            }
        }
        void deleteItem(KeyType k)
        {
            if(head == nullptr)
                return;
            if(head->pairKey == k)
            {
                Node<KeyType, ValueType>* killMe = head;
                head = killMe->next;
                delete killMe;
                if(head!=nullptr)
                    head->prev = nullptr;
                return;
            }
            else
            {
                Node<KeyType, ValueType>* p = head;
                while(p!=nullptr)
                {
                    if(p->pairKey == k)
                        break;
                    p = p->next;
                }
                if(p!=nullptr)
                {
                    Node<KeyType, ValueType>* killMe = p;
                    killMe->prev->next = killMe->next;
                    if(p->next != nullptr)
                        killMe->next->prev = killMe->prev;
                    delete killMe;
                    return;
                }
            }
        }
        bool findItem(const KeyType& k) const
        {
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                if(p->pairKey == k)
                    return true;
                p = p->next;
            }
            return false;
        }
        
        /*void printItems() const
         {
         Node<KeyType, ValueType>* p;
         p = head;
         while(p!=nullptr)
         {
         
         p = p->next;
         }
         }
         */
        
        int getSize() const
        {
            int num = 0;
            if(head == nullptr)
                return 0;
            
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                num++;
                p = p->next;
            }
            return num;
        }
        ~LinkedList()
        {
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                Node<KeyType, ValueType>* n = p->next;
                delete p;
                p = n;
            }
        }
        bool updateList(const KeyType& k, const ValueType& v)
        {
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                if(p->pairKey == k)
                    break;
                p = p->next;
            }
            if(p!=nullptr)
            {
                p->pairValue = v;
                return true;
            }
            return false;
        }
        
        bool getValue(const KeyType& k, ValueType& v) const
        {
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                if(p->pairKey == k)
                    break;
                p = p->next;
            }
            if(p!=nullptr)
            {
                v = p->pairValue;
                return true;
            }
            return false;
        }
        bool getValue(int i, KeyType& k, ValueType& v) const
        {
            if(i>this->getSize() || i<0)
                return false;
            int num = 0;
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                if(num == i)
                    break;
                p = p->next;
                num++;
            }
            if(p!=nullptr)
            {
                k = p->pairKey;
                v = p->pairValue;
                return true;
            }
            return false;
        }
        void clearList()
        {
            Node<KeyType, ValueType>* p = head;
            while(p!=nullptr)
            {
                Node<KeyType, ValueType>* n = p->next;
                delete p;
                p = n;
            }
            head = nullptr;
        }
        
        
        
    private:
        Node<KeyType, ValueType>* head;
        //Node* tail;
        int m_nodeCounter;
        
    };
    
    //LinkedList m_list;
    LinkedList* m_table;
    double m_load;
    int m_numItems;
    int m_size;
};





