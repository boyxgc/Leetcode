class LRUCache{
public:
    LRUCache(int capacity) {
        head = new Cell();
        tail = new Cell();
        head->next = tail;
        tail->prev = head;
        
        size = 0;
        capa = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        } else {
            putAsHead(map[key]);
            return map[key]->val;
        }
    }
    
    void set(int key, int value) {
        Cell * cell;
        if(map.find(key) == map.end()) {
            cell = new Cell(key, value);
            map[key] = cell;
            if(size == capa) {
                Cell *tmp = tail->prev;
                tail->prev = tmp->prev;
                tail->prev->next = tail;
                map.erase(tmp->key);
                delete tmp;
                size--;
            }
            
            size++;
        } else {
            cell = map[key];
            cell->val = value;
        }
        putAsHead(cell);
    }
public:
    struct Cell {
        int key;
        int val;
        Cell* prev;
        Cell* next;
        
        Cell(): prev(NULL), next(NULL) {}
        Cell(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
    };

private:
    Cell *head;
    Cell *tail;
    int size;
    int capa;
    unordered_map<int, Cell*> map;
    
    void putAsHead(Cell * cell) {
        if(cell->prev && cell->next) {
            cell->prev->next = cell->next;
            cell->next->prev = cell->prev;
        }
        cell->next = head->next;
        head->next = cell;
        cell->next->prev = cell;
        cell->prev = head;
    }
};