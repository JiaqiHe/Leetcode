#include <iostream>

struct Folder {
    int id;
    bool isShared;
    int inDegree;
    unordered_set<Folder*> childFolders;
    unordered_set<int> cows;
    Folder(int id, bool isShared): id(id), isShared(isShared), inDegree(0) {}
};

void readCows(unordered_map<int, Folder*> &folders, int M, bool isShared) {
    while(M-- > 0) {
        int id, K;
        cin>>id>>K;
        Folder* cur_folder = new Folder(id, isShared);
        while(K-- > 0) {
            int cow_id;
            cin>>cow_id;
            cur_folder->cows.insert(cow_id);
        }
        folders[id] = cur_folder;
    }
    return;
}

void traverse(vector<int> &cowAccess, Folder* folder, int &numLeaf) {
    if(folder->childFolders.empty()) {
        //leaf node
        numLeaf++;
        for(auto cow_id : folder->cows) {
            cowAccess[cow_id]++;
        }
    } else {
        for(auto f : folder->childFolders) {
            if(f->isShared) {
                for(auto cow_id : folder->cows) {
                    f->cows.insert(cow_id);
                }
            }
            traverse(cowAccess, f, numLeaf);
        }
    }
    
}

int main() {
    int Q,M,N,G;
    // vector<Folder*> folders;
    unordered_map<int, Folder*> folders;
    
    cin>>Q>>M>>N;//# of cows, shared folders, confidential folders
    readCows(folders, M, true);
    readCows(folders, N, false);
    cin>>G;//# of edges
    while(G-- > 0) {
        int U,V;
        cin>>U>>V;
        folders[U]->childFolders.insert(folders[V]);
        folders[V]->inDegree++;
    }
    
    //traverse
    int numLeaf = 0;
    vector<int> cowAccess(Q, 0);
    for(auto p : folders) {
        if(p.second->inDegree == 0) {
            traverse(cowAccess, p.second, numLeaf);
        }
    }
    
    //res
    for(int i = 0; i < Q; i ++) {
        if(cowAccess[i] != numLeaf) cout<<i<<" ";
    }
    
}
