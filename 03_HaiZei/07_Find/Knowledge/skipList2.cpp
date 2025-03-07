struct Node
{
    // 向右向下指针
    Node *right;
    Node *down;
    int val;
    int id;
    Node(Node *right, Node *down, int id, int val) : right(right), down(down), val(val), id(id) {}
};

class Skiplist
{
private:
    Node *head;
    const static int MAX_LEVEL = 32;
    vector<Node *> pathList; // 查找时临时使用的变量

public:
    Skiplist()
    {
        // 初始化头结点
        head = new Node(NULL, NULL, -1, -1);
        pathList.reserve(MAX_LEVEL);
    }

    int search(int target)
    {
        Node *p = head;
        while (p)
        {
            // 左右寻找目标区间
            while (p->right && p->right->val <= target) // target大于等于 val
            {
                if ((target - p->right->val) <= 50) // 找到目标值
                {
                    int id = p->right->id;
                    erase(p->right->val);
                    return id;
                }
                else
                    p = p->right;
            }
            if (!p->right || target < p->right->val) // target 小于 val
            {
                if ((p->right->val - target) <= 50) // 找到目标值
                {
                    int id = p->right->id;
                    erase(p->right->val);
                    return id;
                }
                else
                    p = p->down;
            }
            else
            {
                add(target);
                return -1;
            }
        }
        return -1;
    }

    void add(int num)
    {
        // 从上至下记录搜索路径
        pathList.clear();
        Node *p = head;
        // 从上到下去搜索 次小于num的 数字，等于就是另外一种实现里的 prevs
        while (p)
        {
            // 向右找到次小于num的p
            while (p->right && p->right->val < num)
            {
                p = p->right;
            }
            pathList.push_back(p);
            p = p->down;
        }

        bool insertUp = true;
        Node *downNode = NULL;
        // 从下至上搜索路径回溯，50%概率
        // 这里实现是会保证不会超过当前的层数的，然后靠头结点去额外加层， 即每次新增一层
        while (insertUp && pathList.size() > 0)
        {
            Node *insert = pathList.back();
            pathList.pop_back();
            // add新结点
            insert->right = new Node(insert->right, downNode, num);
            // 把新结点赋值为downNode
            downNode = insert->right;
            // 50%概率
            insertUp = (rand() & 1) == 0;
        }
        // 插入新的头结点，加层
        if (insertUp)
        {
            head = new Node(new Node(NULL, downNode, num), head, -1);
        }
    }

    bool erase(int num)
    {
        Node *p = head;
        bool seen = false;
        while (p)
        {
            // 当前层向右找到次小的点
            while (p->right && p->right->val < num)
            {
                p = p->right;
            }
            // 无效点，或者 太大， 则到下一层去
            if (!p->right || p->right->val > num)
            {
                p = p->down;
            }
            else
            {
                // 搜索到目标结点，进行删除操作，结果记录为true
                // 继续往下层搜索，删除一组目标结点
                seen = true;
                p->right = p->right->right;
                p = p->down;
            }
        }
        return seen;
    }
};