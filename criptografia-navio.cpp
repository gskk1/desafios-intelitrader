#include <iostream>
#include <string.h>
#include <bitset>
#include <sstream>

std::string binario_para_texto(const std::string &binario) {
    std::string texto = "";
    std::stringstream sstream(binario);
    while (sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        texto += char(bits.to_ulong());
    }
    return texto;
}

void inverter_dois_ultimos(std::string &byte)
{
    if (byte[7] == '0') {
        byte[7] = '1';
    } else 
        byte[7] = '0';
        
    if (byte[6] == '0') {
        byte[6] = '1';
    } else 
        byte[6] = '0';
        
}

void trocar_quatro_bits(std::string &byte)
{
    for (auto i=0; i<4; i++)
    {
        int aux = byte[i];
        byte[i] = byte[i+4];
        byte[i+4] = aux;
    }
}

std::string descriptografar (const std::string &msg_entrada)
{
    std::string msg_saida;
    std::string byte;
    std::stringstream ss(msg_entrada);
    while (getline(ss, byte, ' ')) {
        inverter_dois_ultimos(byte);
        trocar_quatro_bits(byte);
        msg_saida.append(byte);
    };

    return binario_para_texto(msg_saida);
}

int main()
{
    std::string codigo = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011" ;
    std::cout << descriptografar(codigo);
    return 0;
}
