programa 
{
	inclua biblioteca Graficos --> graficos
	inclua biblioteca Util --> util
	
	funcao inicio () 
	{ 
		graficos.iniciar_modo_grafico(falso)
		inteiro cor = graficos.criar_cor(100, 0, 0)
		graficos.definir_cor(cor)
		graficos.limpar()
		graficos.renderizar()
		
		inteiro foguete = graficos.carregar_imagem("foguete.png")
		graficos.desenhar_imagem(20, 20, foguete)
		graficos.renderizar()

		//util.aguarde(2000)
		//escreva("Preparando para lan�ar foguete...\n")
		//escreva("5...\n")
		//util.aguarde(1000)
		//escreva("4...\n")
		//util.aguarde(1000)
		//escreva("3...\n")
		//util.aguarde(1000)
		//escreva("2...\n")
		//util.aguarde(1000)
		//escreva("1...\n")
		//util.aguarde(10000)
		

		para(inteiro i=0; i < 1000; i++){
			graficos.limpar()
			util.aguarde(10)
			graficos.desenhar_imagem(250, 400-i, foguete)
			graficos.renderizar()
		}
		
		graficos.encerrar_modo_grafico()
	} 
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 354; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */