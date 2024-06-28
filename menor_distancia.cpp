#include <iostream>
#include <array>

template<std::size_t n>
std::array<int, n> preencher_array()
{
    std::array<int,n> array;
    std::cout << "preencha a array: ";
    for (auto i = 0; i < n; i++)
        std::cin >> array[i];
        
    return array;
}

template<std::size_t n>
void menor_distancia(const std::array<int,n> &array1, const std::array<int,n> &array2)
{
    unsigned int menor_distancia = abs(array1[0] - array2[0]);
    unsigned int posicao_1 = 0;
    unsigned int posicao_2 = 0;
    
    for (auto i = 0; i < n; i++ ){
        for (auto j = 0; j < n; j++ ) { 
            unsigned int distancia = abs(array1[i] - array2[j]);
            if ( distancia < menor_distancia ) {
                menor_distancia = distancia;
                posicao_1 = i;
                posicao_2 = j;
                
            }
        }    
    }

    std::cout << "A menor distancia é: " << menor_distancia << ", combinação do array 1 numero "<< array1[posicao_1] << " e do array 2 numero "<< array2[posicao_2];

}

int main()
{
    /*Neste caso estou preenchendo array de tamanho pre-determinado, poderia deixar o tamanho dinamico utilizando std::vector */
    
    const std::size_t n = 10;
    // std::cout << "Insira o tamanho desejado das arrays: ";
    // std::cin >> n; 
    
    auto array1 = preencher_array<n>();
    std::cout << std::endl;
    auto array2 = preencher_array<n>();

    menor_distancia<n>(array1, array2);
}
