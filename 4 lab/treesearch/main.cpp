#include <bits/stdc++.h>

//оставь надежду всяк сюда входящий

using namespace std;
struct node {
    int key;
    node *left;
    node *right;
    node *parent;
};

node *n;
node *root;

int modmin;
int ournum;

void insert(node *curr, int k) {

    if (curr == NULL) {
        n = new node;
        n->key = k;
        n->left = 0;
        n->right = 0;
    } else if (curr->key > k) {
        insert(curr->left, k);
        if (curr->left == NULL) {
            curr->left = n;
            n->parent = curr;
        }
    } else {
        insert(curr->right, k);
        if (curr->right == NULL) {
            curr->right = n;
            n->parent = curr;
        }
    }

}

node *minimum(node *x) {
    while (x->left != NULL)
        x = x->left;
    return x;
}

node *search(node *curr, int num) {
    if (root->key == num) {
        return root;
    }
    if ((curr == NULL) || (num == curr->key))
        return curr;
    if (num < curr->key)
        return search(curr->left, num);
    else
        return search(curr->right, num);

}

string exists(int k) {
    if (root == NULL) {
        return "false";
    }
    if (search(root, k) == NULL) {
        return "false";
    } else return "true";
}


node *maximum(node *x) {
    while (x->right != NULL)
        x = x->right;
    return x;
}


node *next(int k) {
    node *x = search(root, k);
    if (x != NULL) {
        if (x != NULL && x->right != NULL)
            return minimum(x->right);
        if (x == root) {
            return NULL;
        }
        node *y = x->parent;
        while (y != NULL && x == y->right) {
            x = y;
            if (y != root) { y = y->parent; } else { return NULL; }
        }
        if (exists(y->key) == "true") return y; else return NULL;
    } else {
        modmin = INT_MAX;
        node *m = root;
        while (m != NULL) {
            if (m->key > k) {
                m = m->left;
            } else {
                if (abs(m->key - k) < modmin) {
                    modmin = abs(m->key - k);
                    ournum = m->key;
                }
                m = m->right;
            }
        }
        if (modmin != INT_MAX) {
            return (next(ournum));
        } else {
            node *temp = minimum(root);
            if (temp->key > k)
                return temp;
        }
    }
}

node *prev(int k) {
    node *x = search(root, k);
    if (x != NULL) {
        if (x != NULL && x->left != NULL)
            return maximum(x->left);
        if (x == root) {
            return NULL;
        }
        node *y = x->parent;
        while (y != NULL && x == y->left) {
            x = y;
            if (y != root) { y = y->parent; } else { return NULL; }
        }
        if (exists(y->key) == "true") return y; else return NULL;
    } else {
        modmin = INT_MAX;
        node *m = root;
        while (m != NULL) {
            if (m->key < k) {
                m = m->right;
            } else {
                if (abs(m->key - k) < modmin) {
                    modmin = abs(m->key - k);
                    ournum = m->key;
                }
                m = m->left;
            }
        }
        if (modmin != INT_MAX) {
            return (prev(ournum));
        } else {
            node *temp = maximum(root);
            if (temp->key < k)
                return temp;
        }
    }
}

void del(int k) {
    node *element = search(root, k);

    if (element != NULL) {
        if ((element == root) && (element->left == NULL) && (element->right == NULL)) {
            root = NULL;
        } else if ((element == root) && (element->left == NULL)) {
            root = root->right;
        } else if ((element == root) && (element->right == NULL)) {
            root = root->left;
        } else if ((element->left == NULL) && (element->right == NULL)) {
            if (element == element->parent->left) {
                element->parent->left = NULL;
            } else {
                element->parent->right = NULL;
            }
        } else if (element->left == NULL) {
            if (element == element->parent->left) {
                element->parent->left = element->right;
                element->parent->left->parent = element->parent;
            } else {
                element->parent->right = element->right;
                element->parent->right->parent = element->parent;
            }
        } else if (element->right == NULL) {
            if (element == element->parent->left) {
                element->parent->left = element->left;
                element->parent->left->parent = element->parent;
            } else {
                element->parent->right = element->left;
                element->parent->right->parent = element->parent;
            }
        } else {
            node *temp = minimum(element->right);
            int t = temp->key;
            del(t);
            element->key = t;
        }
    }
}

int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    root = 0;
    string curr;
    int now;
    while (fin >> curr) {
        if (curr == "insert") {
            fin >> now;
            if (root == NULL || exists(now) == "false") {
                insert(root, now);
                if (root == NULL) root = n;
            }
        } else if (curr == "delete") {
            fin >> now;
            if (exists(now) == "true") {
                del(now);
            }
        } else if (curr == "exists") {
            fin >> now;
            fout << exists(now) << endl;
        } else if (curr == "next") {
            fin >> now;
            node *k = NULL;
            if (root != NULL) k = next(now);
            if (k != NULL ) { fout << k->key << endl; } else { fout << "none" << endl; }
        } else if (curr == "prev") {
            fin >> now;
            node *k = NULL;
            if (root != NULL) k = prev(now);
            if (k != NULL) { fout << k->key << endl; } else { fout << "none" << endl; }
        }
    }
    return 0;
}