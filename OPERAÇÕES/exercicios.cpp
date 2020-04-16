#include<opencv2/opencv.hpp> //Biblioteca
#include<opencv2/imgproc.hpp>
#include<iostream>//Biblioteca padrao
#include<stdlib.h>
#include <locale.h> 

using namespace std;
using namespace cv; // defininido o nome dabivlioteca



void TRANSFORMACOES() {

    Mat imagemEntrada, ImagemSize , RotacaoSaida;;
    imagemEntrada = imread("MARIO/Mario2.jpg");

    //OPERAÇÃO ESCALAR
    
    resize(imagemEntrada, ImagemSize, ImagemSize.size(), 0.75, 0.75, INTER_CUBIC);
    imshow("IMAGEM ENTRADA", imagemEntrada);
    imshow("OPERAÇÃO ESCALAR", ImagemSize);
   
   
    
    
    // ROTAÇÃO
   

    Point center = Point(imagemEntrada.cols / 2, imagemEntrada.rows / 2);
    double angulo = -50.0;
    double escalla = 0.6;

    Mat MatrizRotacao = getRotationMatrix2D(center, angulo, escalla);
    warpAffine(imagemEntrada, RotacaoSaida, MatrizRotacao, RotacaoSaida.size());
    imshow("ROTAÇÃO  ", RotacaoSaida);
    waitKey(0);


};
void OPARITMETICO() {
    Mat imaA, imaB, imagemsaidaI, imagemsaidaII, ImagemSub , ImagemAdi,ImagemDiv;
    int linhas, colunas;//vpI, vpII , resultado;
    imaA = imread("MARIO/Mario2.jpg");
    imaB = imread("MARIO/Mario22.jpg");



    cvtColor(imaA, imagemsaidaI, COLOR_RGBA2GRAY);
    cvtColor(imaB, imagemsaidaII, COLOR_RGBA2GRAY);


    if ((imagemsaidaI.rows == imagemsaidaII.rows) && (imagemsaidaI.cols == imagemsaidaII.cols)) {

        linhas = imagemsaidaII.rows;
        colunas = imagemsaidaII.cols;


    }
    else {

        cout << "imagens com proporções erradas";

    }

    /*for (int col = 0; col < imagemsaidaII.cols; col++) {
        for (int lin = 0; lin < imagemsaidaII.rows; lin++) {


            vpI = imagemsaidaI.at<uchar>(lin, col);
            vpII = imagemsaidaII.at<uchar>(lin, col);

            resultado = vpI / vpII;


            ImagemDiv.at<uchar> = saturate_cast<uchar>(resultado);


        }

    }*/

   
    // adição
        ImagemAdi = imagemsaidaI + imagemsaidaII;

        ImagemAdi /= 2;
    // subtração
        ImagemSub = imagemsaidaI - imagemsaidaII;

        ImagemSub += 255;
        ImagemSub /= 2;
  //divisão
        Mat imagemDiv(linhas , colunas , imagemsaidaII.type());

        imagemDiv = imagemsaidaI / imagemsaidaII;


    imshow("Adição", ImagemAdi);
    imshow("Subtração", ImagemSub);
  imshow("Divisão", imagemDiv);
    imshow("IMAGEM ENTRADA I", imagemsaidaI);
    imshow("IMAGEM ENTRADA II", imagemsaidaII);
    waitKey(0);

}
void OPLOGICA() {

  

    Mat imaA, imaB, imagemsaidaI, imagemsaidaII, imagembinI, imagembiII;
    int pixelI, pixelII, linhas, colunas;

    imaA = imread("1bit1.png");
    imaB = imread("2bit2.png");



    cvtColor(imaA, imagemsaidaI, COLOR_RGBA2GRAY);
    cvtColor(imaB, imagemsaidaII, COLOR_RGBA2GRAY);
    threshold(imagemsaidaI, imagembinI, 128, 255, THRESH_BINARY);
    threshold(imagemsaidaII, imagembiII, 128, 255, THRESH_BINARY);

   
 if ((imagembinI.rows == imagembiII.rows) && (imagembinI.cols == imagembiII.cols)) {

        linhas = imagembinI.rows;
        colunas = imagembinI.cols;


 }
 else {

     cout << "imagens com proporções erradas";

 }
 
 Mat imagemAND(linhas, colunas, CV_8UC1);
 Mat imagemOR(linhas, colunas, CV_8UC1);
 Mat imagemNOT(linhas, colunas, CV_8UC1);
 Mat imagemXOR(linhas, colunas, CV_8UC1);
   

        for (int col = 0; col < colunas; col++) {
            for (int lin = 0; lin < linhas; lin++) {

                pixelI = imagembinI.at<uchar>(lin, col);
                pixelII = imagembiII.at<uchar>(lin, col);
                //OPERAÇÃO AND
                if ((pixelI == 255) && (pixelII == 255)) {


                    imagemAND.at<uchar>(lin, col) = 255;



                }
                else {

                    imagemAND.at<uchar>(lin, col) = 0;

                }
                //OPERAÇÃO OR

                if ((pixelI == 255) || (pixelII == 255)) {


                    imagemOR.at<uchar>(lin, col) = 255;



                }
                else {

                    imagemOR.at<uchar>(lin, col) = 0;

                }
                //OPERAÇÃO XOR
                if ((pixelI == 255) && (pixelII == 255) || (pixelI == 0) && (pixelII == 0)) {


                    imagemXOR.at<uchar>(lin, col) = 255;



                }
                else {

                    imagemXOR.at<uchar>(lin, col) = 00;

                }
                //OPERAÇÃO NOT
                if ((pixelI == 255) && (pixelII == 255)) {


                    imagemNOT.at<uchar>(lin, col) = 0;



                }
                else {

                    imagemNOT.at<uchar>(lin, col) = 255;

                }
            }


            
        }


        imshow("IMAGEM ENTRADA - 1", imaA);
        imshow("IMAGEM ENTRADA - 2", imaB);
        imshow("OPERAÇÃO AND:" , imagemAND);
        imshow("OPERAÇÃO OR:", imagemOR);
        imshow("OPERAÇÃO  XOR:", imagemXOR);
        imshow("OPERAÇÃO NOT:", imagemNOT);
        waitKey(0);
           


};

int main() {


    setlocale(LC_ALL, NULL);
    int opc;


    cout << "OPERAÇÕES LOGICA , ARTMERICAS E TRANFORMAÇÕES GEOMETRICAS" << endl;

   do 
    {
        cout << "ESCOLHA UMA OPERAÇÃO ABAIXO:" << endl;

        cout << "1 - OPERAÇÕES LOGICAS" << endl;
        cout << "2 - OPERAÇÕES ARTIMETICAS " << endl;
        cout << "3 - TRANSFORMAÇÕES GEOMETRICAS" << endl;
        cout << "0 - sair " << endl;

        cin >> opc;

        switch (opc)
        {

        case 1:
            OPLOGICA();
            break;
        case 2:
            OPARITMETICO();
            break;
        case 3:
            TRANSFORMACOES();
            break;
        default:
            cout << "OPÇÃO INVALIDA" << endl;

            break;

        }
   } while (opc !=0);
   {

   }
   
    
   


    return 0; 
        
}
