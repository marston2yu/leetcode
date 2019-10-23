#include "LRUCache.h"

int LRUCache::get(int key) {
    if (cache.find(key)==cache.end()) {
        return -1;
    }
    int value = cache[key]->second;
    put(key, value);
    return value;
}

void LRUCache::put(int key, int value) {
    if (cache.find(key)!=cache.end()) { // hit then delete old.
        access.erase(cache[key]);
        cache.erase(key);
    }
    // insert new to refresh cache.
    access.push_front(make_pair(key, value));
    cache[key] = access.begin();
    // reach capacity, delete oldest node.
    if (cache.size() > capacity) {
        cache.erase(access.back().first);
        access.pop_back();
    }
}