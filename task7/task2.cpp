class Storage {
private:
    unsigned int size;
    int* data;

public:
    Storage(unsigned int n) {
        size = n;
        data = new int[n];
    }

    // Так при удалении через Storage* сработает и деструктор наследника.
    virtual ~Storage() {
        delete[] data;
    }

    unsigned getSize() {
        return size;
    }

    int getValue(unsigned int i) {
        return data[i];
    }

    void setValue(unsigned int i, int value) {
        data[i] = value;
    }
};

// Наследник для проверки освобождения памяти, как в условии.
class TestStorage : public Storage {
protected:
    int* more_data;

public:
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }

    ~TestStorage() {
        delete[] more_data;
    }
};

int main() {
    Storage* ts = new TestStorage(42);
    delete ts;
    return 0;
}
