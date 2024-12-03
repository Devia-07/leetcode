#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string nombre,precio,id,id_eliminar,datos,cantidad,id_ver,id_comprar,id_cambiar;




class manejo_archivos{

public:
    manejo_archivos();
    static void ingresar();
    static void actualizar();
    static void eliminar();
    static void listar();
    static void consultar();
    static void comprar();
    //string convertir_string();

    
};



void manejo_archivos::ingresar(){
    
    ofstream documento("prueba.csv",ios::app); // iniciar para escribir en el documento
    //verificamos si el documento se creo
    if(!documento){
        cout<<"error al crear archivo"<<endl;
    }else{
        cout<<"digite el nombre del  producto : "<<endl;
        cin>>nombre;
        cout<<"digite su precio: "<<endl;
        cin>>precio;
        cout<<"digite cantidad de producto"<<endl;
        cin>>cantidad;
        cout<<"digite la id: "<<endl;
        cin>>id;

        //ingresamos los datos al archivo
        documento<<nombre<<","<<precio<<","<<cantidad<<","<<id<<endl;
        documento.close();
        cout<<"Los datos han sido guardados"<<endl;
        
    }

}


void manejo_archivos::eliminar(){
 // leemos el archivo
 ifstream documento("prueba.csv",ios::in); // abrimos en modo lectura
 // verificamos si abrimos el documento
 if(!documento){
    cout<<"no se abrio el documento"<<endl;

 }else{
    vector<string>eliminacion;// creamos un vector para almacenar los datos que no se eliminan
    bool bandera = false;
    
    cout<<"digite el numero de cedula a eliminar"<<endl;
    cin>>id_eliminar;

    while(getline(documento,datos)){
        stringstream registros(datos);// convertimos los datos en string
        getline(registros,nombre,',');
        getline(registros,precio,',');
        getline(registros,cantidad,',');
        getline(registros,id,',');

       if((id_eliminar.compare(id))==0){
        bandera = true;
        


       }else{
        eliminacion.push_back(datos);
       }


    }
    documento.close();
    if(bandera){
        cout<< "usuario eliminado"<<endl;
        ofstream documento_eliminacion("prueba.csv"); // creamos un nuevo documento
        for(int i=0;i<eliminacion.size();i++){
            documento_eliminacion<<eliminacion[i]<<endl;
        }
        documento_eliminacion.close();
    }
    else{
        cout<<"no se encontro la cedula"<<endl;
    }
 }
}
void manejo_archivos::listar(){
    ifstream documento("prueba.csv",ios::in);
    if(!documento){
        cout<<"No documento no abierto"<<endl;
    }
    while(getline(documento,datos)){
        stringstream registros(datos);
        getline(registros,nombre,',');
        getline(registros,precio,',');
        getline(registros,cantidad,',');
        getline(registros,id,',');

        cout<<"nombre del producto: "<<nombre<<endl;
        cout<<"precio: "<<precio<<endl;
        cout<<"cantidad: "<<cantidad<<endl;
        cout<<"id: "<<id<<endl;

    }
    documento.close();



}


void manejo_archivos::consultar(){
    bool bandera = false;
    ifstream documento("prueba.csv",ios::in);
    if(!documento){
        cout<<"documento no abierto"<<endl;

    }else{
        while(getline(documento,datos)){
        stringstream registros(datos);
        cout<<"ingrese la id del producto que quiere ver"<<endl;
        cin>>id_ver;
        
        getline(registros,nombre,',');
        getline(registros,precio,',');
        getline(registros,cantidad,',');
        getline(registros,id,',');

        if(id_ver.compare(id)==0){
            bandera = true;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"precio: "<<precio<<endl;
            cout<<"cantidad: "<<cantidad<<endl;
            
        }
        

    }}
    documento.close();
    if(!bandera){
        cout<<"producto no encontrado"<<endl;
        
    }


}

void manejo_archivos::actualizar(){
    string nuevo_precio,nueva_cantidad;
    bool encontrado = false;
    vector<string> actualizar_admin;
    
    ifstream documento("prueba.csv",ios::in);
    cout<<"ingrese la id del producto a actulizar"<<endl;
    cin>>id_cambiar;
    while(getline(documento,datos)){
        stringstream registros(datos);
        
        getline(registros,nombre,',');
        getline(registros,precio,',');
        getline(registros,cantidad,',');
        getline(registros,id,',');

        if(id_cambiar.compare(id)==0){

            encontrado = true;
            cout<<"Ingrese la cantidad precio del producto"<<endl;
            cin>>nuevo_precio;
            precio = nuevo_precio;
            cout<<"ingrese la nueva cantidad del producto"<<endl;
            cin>>nueva_cantidad;
            cantidad = nueva_cantidad;
            cin.ignore();
            actualizar_admin.push_back(nombre+","+precio+","+cantidad+","+id);
            encontrado = true;
            continue;
            

        }
        actualizar_admin.push_back(nombre+","+precio+","+cantidad+","+id);
    }
    if(encontrado){
        ofstream documento_actualizado("prueba.csv");
        for(int i=0; i<actualizar_admin.size();i++){
            documento_actualizado<<actualizar_admin[i]<<endl;
        }
        cout<<"actualizacion confirmado"<<endl;
    }else{
        cout<<"Producto no encontrado"<<endl;
    }
}


void manejo_archivos::comprar(){
    vector <string> compras_cliente;
    bool encontrado = false;
    bool confirmacion_compra = false;
    listar();
    ifstream documento("prueba.csv");
    cout<<"ingrese la id del producto que quiere comprar"<<endl;
    cin>>id_comprar;
    
    while(getline(documento,datos)){
        stringstream registros(datos);
        
        
        getline(registros,nombre,',');
        getline(registros,precio,',');
        getline(registros,cantidad,',');
        getline(registros,id,',');

        if(id_comprar==id){
            encontrado = true;
            int cantidad_compra = stoi(cantidad);
            if(cantidad_compra > 0){

                cantidad_compra --;
                cantidad = to_string(cantidad_compra);
                compras_cliente.push_back(nombre+","+precio+","+cantidad+","+id);
            cout <<"producto comprado"<<endl;
            confirmacion_compra = true;

            }else{
                cout <<"no hay producto disponible"<<endl;
                compras_cliente.push_back(nombre+","+precio+","+cantidad+","+id);
            }
    continue;       
    }
    
    compras_cliente.push_back(nombre+","+precio+","+cantidad+","+id);
    
    }
     

     if(encontrado == false){
        cout<<"producto no encontrado"<<endl;
        return;
     }
    if(confirmacion_compra){
        ofstream actualizacion_productos("prueba.csv");
        for(int i =0;i<compras_cliente.size();i++){
            actualizacion_productos<<compras_cliente[i]<<endl;;

        }
        
    }
   
}

class Menu{

public:
    Menu();
    void menu_documento();
    
};

Menu::Menu(){
}

void Menu::menu_documento(){
    int opc;
    do{
        cout<<"1. para ingresar datos"<<endl;
        cout<<"2. para elimar datos"<<endl;
        cout<<"3. listar lo del documento"<<endl;
        cout<<"4. saber si esta un producto"<<endl;
        cout<<"5. actulizar info de un producto"<<endl;
        cout<<"6.comprar producto"<<endl;
        cout<<"0.salir"<<endl;
        cin>>opc;
   
    switch(opc){
        case 1:{
            manejo_archivos::ingresar();
            break;
        }
        case 2:{
            manejo_archivos::eliminar();
            break;
        }
        case 3:{
            manejo_archivos::listar();
            break;
        }
        case 4:{
            manejo_archivos::consultar();
            break;
        }
        case 5:{
            manejo_archivos::actualizar();
            break;

        }
        case 6:{
            manejo_archivos::comprar();
            break;
        }
        case 0:{
            cout<<"saliendo hermoso"<<endl;
            break;
        }
        default:
            cout<<"opcion invalida"<<endl;
    }
    
    }
    while(opc!=0);

}




int main(){
    Menu n;
    n.menu_documento();
    
    
    
}

