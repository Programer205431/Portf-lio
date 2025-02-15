# include  < stdio.h >
# include  < stdlib.h >



int p






rincipal ()
{
    
    float area, precoFinal, custo, desconto1, desconto2, erva = 50 , gafanhoto = 100 , broca = 150 , todos = 250 ;
    
    printf ( " Qual a área a ser pulverizada? \n " );
    scanf ( " %f " , &área);
    
    int tipo;
    
    printf ( " Qual o tipo de pulverização? \n " );
    scanf ( " %d " , &tipo);
    
    switch (tipo){
        
        case  1 : printf ( " Ervas daninhas: R$ 50,00 por acre. \n " );
        
        custo = área * erva;
        
        printf ( " Seu custo foi de %.2f \n " , custo);
        
        quebrar ;
        
        case  2 : printf ( " Gafanhotos: R$ 100,00 por acre. \n " );
        
        custo = área * gafanhoto;
        
        printf ( " Seu custo foi de %.2f \n " , custo);
        
        quebrar ;
        
        case  3 : printf ( " Broca: R$ 150,00 por acre. \n " );
        
        custo = área * broca;
        
        printf ( " Seu custo foi de %.2f \n " , custo);
        
        quebrar ;
        
        case  4 : printf ( " Ervas, gafanhotos e broca: R$ 250,00 por acre. \n " );
        
        custo = área * todos;
        
        printf ( " Seu custo foi de %.2f \n " , custo);
        
        quebrar ;
        
    }
    
    if (área > 1000 ){
        
        desconto1 = custo * 0,95 ;
        
        printf ( " Após o desconto, seu preço foi de: %.2f \n " , desconto1);
        
    }
    
    if (custo > 750 ){
        
        desconto1 = desconto1 - ((desconto1 - 750 ) * 0,1 );
        
        printf ( " Após o segundo desconto, seu preço foi de: %.2f \n " , desconto1);
        
    }
    
    retorna  0 ;
}
