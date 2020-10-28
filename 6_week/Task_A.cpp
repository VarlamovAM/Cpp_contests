#include <iostream>
#include <utility>
#include <vector>
#include <forward_list>



class hash_table{
    public:

        hash_table(int Size = 512){
            Data_.resize(size_);
            size_ = Size;
            data_el_ = 0;
        };

        bool add(int32_t key, uint32_t value){
            auto par = &Data_.at(hash_compile_(key) % size_);
            for(auto meas_pair = par->begin(); meas_pair != par->end(); meas_pair++) {
                if(meas_pair->first == key){
                    meas_pair->second = value;
                    return true;
                };
            };

            par->push_front(std::make_pair(key, value));

            data_el_++;

            rehash_checking_();

            return false;
        };


        uint32_t find(int32_t key){
            auto par = &Data_.at(hash_compile_(key) % size_);
            for(auto meas_pair : *par){
                if(meas_pair.first == key){
                    return meas_pair.second;
                }
            };
            return 0xFFFFFFFF;
        };

        bool remove(int32_t key){
            auto par = &Data_.at(hash_compile_(key) % size_);
            auto prevpair = par->before_begin();
            for(auto meas_pair = par->begin(); meas_pair != par->end(); meas_pair++){
                if(meas_pair->first == key){
                    par->erase_after(prevpair);
                    data_el_--;
                    rehash_checking_();
                    return true;
                };
                prevpair = meas_pair;
            };
            return false;
        };

        int get_size(){
            return size_;
        };

    private:

        int size_;
        int data_el_;

        std::vector<std::forward_list<std::pair<int32_t, uint32_t>>> Data_;

        uint32_t hash_compile_(int32_t key){

            uint32_t* data = reinterpret_cast<uint32_t*>(&key);
            uint32_t inv_valu = *data;
            int i = 0;
            for(i = 0; i < 32; i++){
                if(inv_valu / 0x7FFFFFFF){
                    inv_valu = inv_valu << 1;
                    inv_valu ^= 0x1EDC6F41;
                } else {
                    inv_valu = inv_valu << 1;
                };
            };
            i = 0;
            return inv_valu;
        };

        bool rehash_checking_(){
            if(data_el_ >= size_ / 2){
                re_hashing_();
                return true;
            } else {
                return false;
            }
        };

        void re_hashing_(){

            std::vector<std::forward_list<std::pair<int32_t, uint32_t>>> base_obj = std::move(Data_);
            size_ *= 4;
            Data_ = std::vector<std::forward_list<std::pair<int32_t, uint32_t>>>(size_);
            for(auto par : base_obj){
                for(auto meas_pair : par){
                    add(meas_pair.first, meas_pair.second);
                };
            };
        };
};



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<hash_table> table;
    table.resize(N);

    int index;
    char operation;
    int32_t key;
    uint32_t value;
    for(int i = 0; i < M; i++){
        std::cin >> index >> operation >> key >> value;
        switch(operation){
            case '+':
                table.at(index).add(key, value);
                break;
            case '-':
                table.at(index).remove(key);
                break;
            case '?':
            {
                uint32_t to_print = table.at(index).find(key);
                if(to_print == 0xFFFFFFFF){
                    std::cout << value << '\n';
                } else {
                    std::cout << to_print << '\n';
                };
                break;
            };
            default:
                std::cout << "Invalid operation\n";
                break;
        };
    };

    return 0;
};
