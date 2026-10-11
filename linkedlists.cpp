#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node* next;
    //tapşırıq 1
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {
    // tapşırıq 2 sona node əlavə etmək
    Node*first = new Node(15);
    Node*second = new Node(20);
    Node*third = new Node(23);
    Node*fourth = new Node(27);
    Node*fifth = new Node(30); 
    //burada yeni node lər əlavə etdim  
    //aşağıda isə nodeləri bir-biri ilə əlaqələndirdim (->)- bu işarə ilə
    first->next = second;
    second-> next = third;
    third-> next = fourth;
    fourth-> next = fifth;
    fifth-> next = nullptr;
    //axırıncının növbətisi bizə null verməli idi
    // tapşırıq 3
    Node* newNode = new Node(10);
    Node*x = newNode; // Qeyd burada biz 10-u 1-cinin qarşısına keçirdiyimiz üçün bu kodda əvvəl first yazmışdıqsa indi newNode yazmalıyıqki əlavə etdiyimiz 10dan başlasın 

    newNode->next = first;
    //tapşırıq 4
    Node* Node_next = new Node(32); //burada zinciri qırırıq və araya qoymaq istədiyimiz nodu əvvəlki bağlantısı və növbəti bağlantısı ilə harada olduğunu bəlli edirik
    third->next = Node_next; 
    Node_next->next = fourth;
    //tapşırıq 5
    Node* delsecond = first-> next; //ikincini silmək istəyirik və dəyişəni birincidən sonraki olaraq veririk buda seconddu ve onun nexti avto qosulur thirde delete delsecond silme icra edir
    first->next = delsecond-> next;
    delete delsecond;
    

    //tapşırıq 6
    int a;
    cin >> a;
    bool found = false;
    while(newNode != nullptr){
        if(newNode->data == a){
            found = true;
            break;
        }
        newNode= newNode-> next;
    }

    if(found){
        cout << "Bu ədəd mövcuddur" << "\n";
    }
    else{
        cout << "Bu ədəd mövcud deyil" << "\n";
    }

    // Tapşırıq 7. Uzunluğun hesablanması
    int length = 0;
    Node* temp7 = first; // Siyahının uzunluğunu hesablamaq üçün başlanğıcdan başlayırıq
    while(temp7 != nullptr) {
        length++;
        temp7 = temp7->next;
    }
    cout << "List length = " << length << "\n";


    // Tapşırıq 8. Maksimum və minimum element
    Node* temp8 = first;
    int maxVal = temp8->data;
    int minVal = temp8->data;
    while(temp8 != nullptr) {
        if(temp8->data > maxVal) {
            maxVal = temp8->data;
        }
        if(temp8->data < minVal) {
            minVal = temp8->data;
        }
        temp8 = temp8->next;
    }
    cout << "Maksimum element: " << maxVal << "\n";
    cout << "Minimum element: " << minVal << "\n";


    // Tapşırıq 9. Siyahını tərs çevirmək
    Node* prev = nullptr;
    Node* current = first;
    Node* nextNode = nullptr;
    while(current != nullptr) {
        nextNode = current->next; // Növbətini qoruyuruq
        current->next = prev;     // Bağlantını əksinə çeviririk
        prev = current;           // prev-i irəli aparırıq
        current = nextNode;       // current-i irəli aparırıq
    }
    first = prev; // Yeni başlanğıc (tərs çevrilmiş siyahının başı)


    // Tapşırıq 10 (Challenge): Tələbə qeydiyyat sistemi
    // Struct tərifini və əməliyyatların nümunə strukturunu burada qura bilərik:
    struct StudentNode {
        int student_id;
        string student_name;
        double gpa;
        StudentNode* next;

        StudentNode(int id, string name, double student_gpa) {
            student_id = id;
            student_name = name;
            gpa = student_gpa;
            next = nullptr;
        }
    };

    // Tələbə siyahısının başlanğıcı
    StudentNode* studentHead = nullptr;

    // Tələbə əlavə etmək (Sona əlavə)
    auto addStudent = [&](int id, string name, double gpa) {
        StudentNode* newStudent = new StudentNode(id, name, gpa);
        if (studentHead == nullptr) {
            studentHead = newStudent;
        } else {
            StudentNode* curr = studentHead;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newStudent;
        }
    };

    // Nümunə olaraq tələbələr əlavə edirik və tələb olunan əməliyyatları yoxlayırıq:
    addStudent(1, "Ali", 85.5);
    addStudent(2, "Leyla", 78.0);
    addStudent(3, "Murad", 92.0);

    // Bütün tələbələri göstər
    cout << "Bütün Tələbələr\n";
    StudentNode* sCurr = studentHead;
    while(sCurr != nullptr) {
        cout << "ID: " << sCurr->student_id << ", Ad: " << sCurr->student_name << ", GPA: " << sCurr->gpa << "\n";
        sCurr = sCurr->next;
    }

    //GPA > 80 olanları göstər
    cout << "GPA > 80 olanlar\n";
    sCurr = studentHead;
    while(sCurr != nullptr) {
        if(sCurr->gpa > 80) {
            cout << sCurr->student_name << " (GPA: " << sCurr->gpa << ")\n";
        }
        sCurr = sCurr->next;
    }

    // Siyahıdakı tələbələrin sayını göstər
    int studentCount = 0;
    sCurr = studentHead;
    while(sCurr != nullptr) {
        studentCount++;
        sCurr = sCurr->next;
    }
    cout << "Siyahıdakı tələbələrin sayı: " << studentCount << "\n";
    

   

    while(x != nullptr){
        cout << x->data << " -> ";
        
        x = x->next;
        //burada x i birincini götürürük null olmağıdı periodda növbəti rəqəmi çap etməyə davam edir "->"- bu sadəcə görüntü məqsədlidir
    }
    cout << " None"<< "\n";

    return 0;
}