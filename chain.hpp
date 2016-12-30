#ifndef CHAIN
#define CHAIN
    template<typename T>
    class chain {
    private:
        int count = 1;
        T object;
        chain<T>* previous_link;

    public:
        chain(const T& object) {
            this->object = object;
        }

        chain() {
            this->object = T();
            count = 0;
        }

        ~chain() {
            while (previous_link != nullptr)
                pop();
        }

        void push(const T& object) {
            if (count >= 1) {
                chain<T>* new_link = new chain<T>(this->object);
                new_link->count = count;
                new_link->previous_link = previous_link;
                previous_link = new_link;
            }

            this->object = object;
            count++;
        }

        const T pop() {
            if (previous_link == nullptr)
                return (count <= 0)? T() : object;

            T temp_object = object;
            object = previous_link->object;
            count --;
            
            chain<T>* temp_link = previous_link;
            previous_link = previous_link->previous_link;
            
            if (previous_link != nullptr) {
                temp_link->previous_link = nullptr;
                delete temp_link;
            }

            return temp_object;
        }

        int size() {
            return count;
        }

        void swap(chain<T>& link) {
            T& temp_object = object;
            object = link.object;
            link.object = temp_object;
            link.count ^= count ^= link.count ^= count;

            chain<T>* previous = link.previous_link;
            link.previous_link = previous_link;
            previous_link = previous;
        }

        const T& top() {
            return object;
        }
    };
#endif
