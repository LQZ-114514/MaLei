#include <iostream>
#include "ChainedHashTable.h"
#include"OpenHashTable.h"

using namespace std;

void printStatus(const MaLei::ChainedHashTable& ht) {
    cout << "[Status] size: " << ht.size() << ", empty: " << (ht.empty() ? "Yes" : "No") << endl;
}

int main() {
    

    MaLei::OpenHashTable ht(5);

    cout << "=== 1. Create collisions and insert 4 elements ===" << endl;
    // Keys 1, 6, 11 will collide. 
    ht.put(1, 100);
    ht.put(6, 600);
    ht.put(11, 1100);
    ht.put(16, 1600); // At this point, loadFactor = 4/5 = 0.8 > 0.75, which triggers auto-rehash!
    
    cout << "After auto-rehash, capacity should be 10 (5 * 2)" << endl;
    cout << "Current Load Factor: " << ht.loadFactor() << endl;
    ht.print();

    cout << "\n=== 2. Create tombstones (DELETED) ===" << endl;
    ht.remove(1);
    ht.remove(6);
    ht.print(); // You should see slots 1 and 6 marked as DELETED

    cout << "\n=== 3. Verify probing chain is not broken ===" << endl;
    cout << "get(11): " << ht.get(11) << " (Expected 1100)" << endl;

    cout << "\n=== 4. Trigger manual rehash to clean up tombstones ===" << endl;
    // At this point, count = 2 (only 11 and 16), capacity = 10. 
    // loadFactor = 0.2, so it won't trigger auto-rehash.
    // We manually call rehash(20) to force a cleanup.
    ht.rehash(20);
    cout << "After rehash(20), tombstones should be completely removed:" << endl;
    ht.print(); // Previous DELETED slots should now be EMPTY



    return 0;
}