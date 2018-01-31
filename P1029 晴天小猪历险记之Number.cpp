#include <unordered_set>
#include <iostream>
#include <string>

const int BEST = 15;
const int DIGITAL[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

struct Position {
    int soldier[3][3];
};

struct Node {
    Position p;
    int depth;
    Node *next;
};

class Arrangement {
public:
    explicit Arrangement(Position p) {
        result = -1;
        head = nullptr;
        tail = nullptr;
        add_node(p, 0);
    };

    ~Arrangement() {
        while (head) {
            Node *tmp = head->next;
            delete head;
            head = tmp;
        }
    };

    void bfs() {
        while (head) {
            if (check_position(&head->p)) {
                result = head->depth;
                break;
            }
            Position p;

            // 十二种交换方式
            p = head->p;
            std::swap(p.soldier[0][0], p.soldier[0][1]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[0][1], p.soldier[0][2]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[1][0], p.soldier[1][1]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[1][1], p.soldier[1][2]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[2][0], p.soldier[2][1]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[2][1], p.soldier[2][2]);
            add_node(p, head->depth + 1);
            p = head->p;

            std::swap(p.soldier[0][0], p.soldier[1][0]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[0][1], p.soldier[1][1]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[0][2], p.soldier[1][2]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[1][0], p.soldier[2][0]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[1][1], p.soldier[2][1]);
            add_node(p, head->depth + 1);
            p = head->p;
            std::swap(p.soldier[1][2], p.soldier[2][2]);
            add_node(p, head->depth + 1);

            head = head->next;
        }
    };

    int result;

private:
    std::unordered_set<int> visited;
    Node *head;
    Node *tail;

    void add_node(Position p, int depth) {
        int hash = get_hash(&p);
        if (visited.count(hash)) {
            return;
        }
        visited.insert(hash);

        auto *new_node = new Node();
        new_node->next = nullptr;
        new_node->depth = depth;
        new_node->p = p;
        if (!tail) {  // init
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    bool check_position(Position *p) {
        if (
                p->soldier[0][0] + p->soldier[0][1] + p->soldier[0][2] == BEST &&
                p->soldier[1][0] + p->soldier[1][1] + p->soldier[1][2] == BEST &&
                p->soldier[2][0] + p->soldier[2][1] + p->soldier[2][2] == BEST &&
                p->soldier[0][0] + p->soldier[1][1] + p->soldier[2][2] == BEST &&
                p->soldier[0][2] + p->soldier[1][1] + p->soldier[2][0] == BEST &&
                p->soldier[0][0] + p->soldier[1][0] + p->soldier[2][0] == BEST &&
                p->soldier[0][1] + p->soldier[1][1] + p->soldier[2][1] == BEST &&
                p->soldier[0][2] + p->soldier[1][2] + p->soldier[2][2] == BEST
                )
            return true;
        return false;
    };

    int get_hash(Position *p) {
        int hash = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                hash += DIGITAL[i * 3 + j] * p->soldier[i][j];
            }
        }
        return hash;
    };
};


int main() {
    std::string s;
    while (true) {
        std::getline(std::cin, s);
        if (!s.length()) {
            break;
        }
        Position p;
        for (int i = 0; i < 3; i++) {
            p.soldier[0][i] = int(s[i * 2] - '0');
        }
        std::getline(std::cin, s);
        for (int i = 0; i < 3; i++) {
            p.soldier[1][i] = int(s[i * 2] - '0');
        }
        std::getline(std::cin, s);
        for (int i = 0; i < 3; i++) {
            p.soldier[2][i] = int(s[i * 2] - '0');
        }
        auto *arrangement = new Arrangement(p);
        arrangement->bfs();
        std::cout << arrangement->result << std::endl;
        delete arrangement;
    }
    return 0;
}