struct CustomItem
{
    int key;
    int value;
    int count_in_cache;

    CustomItem() : key(-1), value(-1), count_in_cache(0) {}
};

class LRUCache {
    
    private:
    int item_count;
    int capacity;
    std::unordered_map<int, std::shared_ptr<CustomItem>> map;
    std::list<std::shared_ptr<CustomItem>> recently_used;

    void evict_last()
    {
        auto& last = recently_used.front();

        last->count_in_cache--;

        if(last->count_in_cache == 0)
        {
            map.erase(last->key);
            recently_used.pop_front();
        }
        else
        {
            // We didn't actually evict anything
            recently_used.pop_front();
            evict_last();
        }
    }

    void touch_item(std::shared_ptr<CustomItem>& item)
    {
        if(item->count_in_cache == 0)
        {
            if(item_count>=capacity)
                evict_last();
            else
                item_count++;
        }

        item->count_in_cache++;
        recently_used.push_back(item);
    }

    public:
        LRUCache(int capacity) 
        {
            this->item_count = 0;
            this->capacity = capacity;
        }
        
        int get(int key) 
        {
            auto it = map.find(key);

            if(it != map.end())
            {                
                touch_item(it->second);
                return (it->second)->value;
            }

            return -1;
        }
        
        void put(int key, int value) 
        {
            auto it = map.find(key);

            if(it != map.end())
            {
                (it->second)->value = value;
                touch_item((it->second));
            }
            else
            {
                map[key] = std::make_shared<CustomItem>();
                map[key]->key = key;
                map[key]->value = value;
                touch_item(map[key]);
            }
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */