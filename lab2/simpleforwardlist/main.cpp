//
// Created by bartek on 06.03.17.
//

int main(void){
    int i,n;
    ForwardList list;
    init(&list);
    
    Append(&list,5884);
    PushFront(&list,1245);
    Append(&list,54);
    Append(&list,119);

    printList(&list);

    DestroyList(&list);


    return 0;
}