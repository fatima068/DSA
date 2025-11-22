/*You are required to implement a game titled “BattleQuest: BST Arena” using a Binary Search Tree (BST) where each node in the tree stores a Combatant object. This game simulates a classic RPG-style battle between a player’s team of heroes and a team of enemies. The core challenge involves managing two separate BSTs — one for the player’s team and another for the enemy team — where each node contains a Combatant object with attributes such as name, health points (HP), and attack power. The game follows a strict turn-based combat system, where the player’s team and the enemy team alternate turns. Only the frontline combatant — defined as the node with the smallest key value (i.e., the leftmost node in the BST) participates in combat during each turn.

When a combatant’s health drops to zero or below, that combatant is removed from their respective BST. The next available combatant in the tree (the new leftmost node) becomes the frontline fighter for the following turn. The battle continues until one team’s BST becomes empty, determining the winner. The player’s team should be initialized with five heroes. The enemy team should be initialized with five enemies.

Both trees should be constructed using insertions according to the BST property based on the combatant’s name or unique ID. The player always attacks first in each round, followed by the enemy counterattack.

During an attack: The attacker’s damage = base attack power + random value (0 to 4)
The damage will affect the defender’s health. If the defender’s health ≤ 0, they are removed from their BST immediately. The next combatant automatically takes their place as the new frontline fighter.

During each turn, the game must display the following information clearly:
    -Round number
    -Names and current HP of all heroes and enemies (in BST order)
    -Active attackers and defenders
    -Damage dealt in the attack
    -Updated HP values after each hit
    -Elimination messages when a combatant is defeated
    -Victory message when one BST becomes empty*/
#include <iostream>
#include <string>
using namespace std;
class Combatant{
    public: 
    int uniqueID;
    string name;
    int healthPts;
    int attackPower;
    Combatant(string name, int healthPts, int attackPower, int uniqueID){
        this->name=name;
        this->healthPts = healthPts;
        this->attackPower = attackPower;
        this->uniqueID= uniqueID;
    }
};

class Node{
    public:
    Combatant* combatant;
    Node *left, *right;
    Node(Combatant* combatant) :combatant(combatant), left(nullptr), right(nullptr) {}
};

class BST{
    public:
    Node* root;
    BST() : root(nullptr) {}

    Node* insertVal(Node* root,Combatant* combatant) {
        if (root== nullptr) {
            return new Node(combatant);
        }
        if (combatant->uniqueID== root->combatant->uniqueID) {
            cout << "insert only unique combatant ids" << endl;
            return root; 
        }
        if (combatant->uniqueID< root->combatant->uniqueID) {
            root->left =insertVal(root->left,combatant);
        }else{
            root->right = insertVal(root->right , combatant);
        }
        return root;
    }

    Node* getMinNode(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int id) { 
        if (root == nullptr) {
            cout<< "not found" << endl;
            return root;
        }else if (id< root->combatant->uniqueID){
            root->left = deleteNode(root->left, id);
        }
        else if (id >root->combatant->uniqueID) {
            root->right = deleteNode(root->right, id);
        }
        else {
            if (root->left== nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right== nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* temp = getMinNode(root->right);
                root->combatant = temp->combatant;
                root->right = deleteNode(root->right, temp->combatant->uniqueID);             
            }
        }
        return root;
    }
    bool isEmpty(){ return root == nullptr;}
    
    void displayCombatants(Node* node) {
        if (node != nullptr) {
            displayCombatants(node->left);
            cout<< node->combatant->uniqueID<<", " <<node->combatant->name <<", HP: " << node->combatant->healthPts;
            displayCombatants(node->right);
        }
    }
};


int getRandomDamage() {
    return rand()%5;
}

void displayRoundInfo(int round, BST& playerTeam, BST& enemyTeam,  string attacker, string defender, int damage,  int newHP, bool elimination = false){
    cout << "round " << round<< endl;
    cout << "Player Team: ";
    playerTeam.displayCombatants(playerTeam.root);
    cout << endl;
    cout << "Enemy Team: ";
    enemyTeam.displayCombatants(enemyTeam.root);
    cout << endl;
    cout << "Attacker: " << attacker << endl;
    cout << "Defender: " << defender << endl;
    cout << "Damage: " << damage << endl;
    cout << defender << "'s HP after attack: " <<newHP << endl;
    if (elimination){
        cout<< defender << " ELIMINATED" << endl;
    }
}

int main(){
    srand(time(0));
    BST playerTeam;
    BST enemyTeam;
    playerTeam.root=playerTeam.insertVal(playerTeam.root,new Combatant("HeroA", 30, 5, 1));
    playerTeam.root= playerTeam.insertVal(playerTeam.root ,new Combatant("HeroB", 25, 6, 3));   
    playerTeam.root= playerTeam.insertVal(playerTeam.root, new Combatant("HeroC", 28, 4, 5));
    playerTeam.root= playerTeam.insertVal(playerTeam.root,new Combatant("HeroD", 32, 7, 7));
    playerTeam.root= playerTeam.insertVal(playerTeam.root, new Combatant("HeroE", 27, 5, 9));
    enemyTeam.root= enemyTeam.insertVal(enemyTeam.root,new Combatant("EnemyA", 26, 6, 2));
    enemyTeam.root= enemyTeam.insertVal(enemyTeam.root,new Combatant("EnemyB", 29, 5, 4));
    enemyTeam.root= enemyTeam.insertVal(enemyTeam.root,new Combatant("EnemyC", 24, 7, 6));
    enemyTeam.root= enemyTeam.insertVal(enemyTeam.root,new Combatant("EnemyD", 31, 4, 8));
    enemyTeam.root= enemyTeam.insertVal(enemyTeam.root,new Combatant("EnemyE", 30, 6, 10));
    int round = 1;
    cout << "BATTLEQUEST: BST ARENA" << endl;
    cout << "Initial Teams:" << endl;
    cout << "Player Team: ";
    playerTeam.displayCombatants(playerTeam.root);
    cout << endl;
    cout << "Enemy Team: ";
    enemyTeam.displayCombatants(enemyTeam.root);
    cout <<endl<<endl << "STARTING GAME..." << endl;

    while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
        Node* playerFrontline =playerTeam.getMinNode(playerTeam.root);
        Node* enemyFrontline =enemyTeam.getMinNode(enemyTeam.root);
        if (playerFrontline && enemyFrontline) {
            int damage = playerFrontline->combatant->attackPower + getRandomDamage();
            enemyFrontline->combatant->healthPts -= damage;
            bool enemyEliminated = false;
            if (enemyFrontline->combatant->healthPts <= 0) {
                displayRoundInfo(round, playerTeam, enemyTeam,  playerFrontline->combatant->name,  enemyFrontline->combatant->name,  damage, 0, true);
                enemyTeam.root = enemyTeam.deleteNode(enemyTeam.root, enemyFrontline->combatant->uniqueID);
                enemyEliminated = true;
            } 
            else{ displayRoundInfo(round, playerTeam, enemyTeam,  playerFrontline->combatant->name,  enemyFrontline->combatant->name,  damage, enemyFrontline->combatant->healthPts);}
            
            if (!enemyTeam.isEmpty()&&enemyEliminated ==false) {
                playerFrontline = playerTeam.getMinNode(playerTeam.root);
                enemyFrontline = enemyTeam.getMinNode(enemyTeam.root);
                if (playerFrontline && enemyFrontline) {
                    int counterDamage = enemyFrontline->combatant->attackPower + getRandomDamage();
                    playerFrontline->combatant->healthPts-= counterDamage;
                    if (playerFrontline->combatant->healthPts<= 0) {
                        displayRoundInfo(round, playerTeam, enemyTeam,  enemyFrontline->combatant->name,  playerFrontline->combatant->name,  counterDamage, 0, true);
                        playerTeam.root = playerTeam.deleteNode(playerTeam.root, playerFrontline->combatant->uniqueID);
                    } 
                    else{ displayRoundInfo(round, playerTeam, enemyTeam, enemyFrontline->combatant->name, playerFrontline->combatant->name, counterDamage, playerFrontline->combatant->healthPts); }
                }
            }
        }
        round++;
    }
    if (playerTeam.isEmpty() && enemyTeam.isEmpty()) {cout << "GAME DRAW!"<< endl;} 
    else if (playerTeam.isEmpty()) { cout << "ENEMY TEAM WINS" << endl;}
    else{ cout << "PLAYER TEAM WINS!" << endl;}
}