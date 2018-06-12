#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Huffman {
    private:
        struct item{
            char charr;
            int frequency;
            struct item *left;
            struct item *right;
        };
        int heap_size;
        vector<item*> hp;
        string sample;
        vector<short> freq;
        item *huff_tree;

        item *newNode(item it) {
            item *root = new (nothrow) (item);
            root -> charr = it.charr;
            root -> frequency = it.frequency;
            root -> left = it.left;
            root -> right = it.right;
            return root;
        }

        void min_heapify(int i) {
            int l = 2*i + 1, r = 2*i + 2, smallest = i;
            if(l < this->heap_size && this->hp[i]->frequency > this->hp[l]->frequency)
                smallest = l;
            if(r < this->heap_size && this->hp[smallest]->frequency > hp[r]->frequency)
                smallest = r;
            if(smallest != i) {
                swap(this->hp[i], this->hp[smallest]);
                this->min_heapify(smallest);
            }
        }
        
        void build_heap() {
            for(int i = floor(this->heap_size/2); i >= 0; i--)
                this->min_heapify(i);
        }

        void decrease_key(int key, item *val) {
            for(int i = key; i >= 0; i /= 2) {
                if(this->hp[i]->frequency < this->hp[(i-1)/2]->frequency)
                    swap(this->hp[i], this->hp[(i-1)/2]);
                else
                    return;
            }
        }

        void increase_key(int key, item *val) {
            this->hp[key] = val;
            this->min_heapify(key);
        }

        void generate_freq() {
            for(int i = 0; i < 256; i++)
                this->freq.push_back(0);
            for(int i = 0; i < this->sample.length(); i++) {
                this->freq[this->sample[i]]++;
            }
        }

        item *huff_stuff() {
            int total_char = heap_size;
            for(int i = 1; i < total_char; i++) {
                this->print_as_array();
                cout<<endl;
                item z;
                z.charr      = 63;
                z.left       = this->extractMin();
                z.right      = this->extractMin();
                z.frequency  = z.left->frequency + z.right->frequency;
                this->insert(newNode(z));
            }
            this->print_as_array();
            return extractMin();
        }
        
        #define COUNT 10 
        void printt(item *root, int space = 0) {
            if (root == nullptr)
                return;
            space += COUNT;
            printt(root->right, space);
            cout<<endl;
            for (int i = COUNT; i < space; i++)
                cout<<" ";
            cout<<root->charr<<"("<<root->frequency<<")\n";
            printt(root->left, space);
        }

        int isLeaf(item* root){
            return !(root->left) && !(root->right);
        }
        
        void PrintCodes(item *root, int arr[], int top){
            if (root->left) { 
                arr[top] = 0;
                this->PrintCodes(root->left, arr, top + 1);
            }
            if (root->right) { 
                arr[top] = 1;
                this->PrintCodes(root->right, arr, top + 1);
            }
 
            if (this->isLeaf(root)) {
                cout<<root->charr<<": ";
                for(int i = 0; i < top; i++)
                    cout<<arr[i];
                cout<<endl;
            }
        }

    public:
        Huffman(string str) {
            this->sample = str;
            this->generate_freq();
            this->heap_size = 0;
            for(int i = 0; i < 256; i++) {
                if(this->freq[i] != 0) {
                    item it;
                    it.charr = i;
                    it.frequency = freq[i];
                    it.left  = nullptr;
                    it.right = nullptr;
                    this->hp.push_back(this->newNode(it));
                    heap_size++;
                }
            }
            this->build_heap();
            this->huff_tree = this->huff_stuff();
        }

        item *extractMin() {
            swap(this->hp[0], this->hp[--heap_size]);
            min_heapify(0);
            return this->hp[heap_size];
        }

        void insert(item *it) {
            if(this->hp.size() > this->heap_size) {
                this->hp[heap_size] = it;
            } else {
                this->hp.push_back(it);
            }
            this->decrease_key(this->heap_size++, it);
        }

        void print() {
            this->printt(this->huff_tree, 0);
        }

        void print_as_array() {
            for(int i = 0; i < heap_size; i++) 
                cout<<i<<".\t"<<this->hp[i]->charr<<"("<<this->hp[i]->frequency<<")\n";
            cout<<endl;
        }

        void printCodes() {
            int arr[100], top; // 100 is just a number random 
            this->PrintCodes(this->huff_tree, arr, top);
        }



};

int main()
{
    //string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbccccccccccccddddddddddddddddeeeeeeeeefffff";
    //string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccdddddeeeff";
    string str = "A quick brown fox jumped over a lazy old dog.";
    Huffman huff(str);
    cout<<"Huffman tree is -> \n";
    huff.print();
    cout<<"\nNow for the code ->\n";
    huff.printCodes();
    return 0;
}
