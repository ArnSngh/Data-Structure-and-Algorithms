class Solution {
public:
    Node* intersect(Node* t1, Node* t2) {
        /* 1. one side is all-1 leaf → result is 1 everywhere */
        if (t1->isLeaf && t1->val) return t1;
        if (t2->isLeaf && t2->val) return t2;

        /* 2. both leaves */
        if (t1->isLeaf && t2->isLeaf)
            return new Node(t1->val | t2->val, true);

        /* 3. expand any remaining leaf into 4 separate leaves */
        if (t1->isLeaf) t1 = expandLeaf(t1->val);
        if (t2->isLeaf) t2 = expandLeaf(t2->val);

        /* 4. recurse on the four pairs */
        Node* tl = intersect(t1->topLeft,  t2->topLeft);
        Node* tr = intersect(t1->topRight, t2->topRight);
        Node* bl = intersect(t1->bottomLeft,  t2->bottomLeft);
        Node* br = intersect(t1->bottomRight, t2->bottomRight);

        /* 5. merge if all four children are identical leaves */
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tl->val == bl->val && tl->val == br->val) {
            bool v = tl->val;
            delete tl; delete tr; delete bl; delete br;
            return new Node(v, true);
        }
        return new Node(false, false, tl, tr, bl, br);
    }

private:
    /* create a non-leaf whose four children are *distinct* leaves */
    Node* expandLeaf(bool v) {
        return new Node(false, false,
                        new Node(v, true),
                        new Node(v, true),
                        new Node(v, true),
                        new Node(v, true));
    }
};