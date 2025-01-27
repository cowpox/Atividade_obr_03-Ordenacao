
# **Projeto: Bubble e Quick**

---

## **Descrição**

Este projeto foi desenvolvido como parte de um estudo acadêmico para comparar os algoritmos de ordenação **Bubble Sort** e **Quick Sort**. O objetivo principal é ordenar os pratos de um restaurante fictício, priorizando sua classificação de acordo com critérios de prioridade e tempo de preparo.

O projeto também explora estratégias para otimizar o desempenho do **Quick Sort**, destacando a escolha de diferentes pivôs, como o pivô à direita e a mediana de 3.

---

## **Enunciado**

Joãozinho está planejando abrir um restaurante especializado em comida britânica e pediu ajuda para priorizar os pratos do cardápio. Ele acredita que o algoritmo **Bubble Sort** seria adequado para essa tarefa. No entanto, foi implementado o **Quick Sort** para demonstrar uma solução mais eficiente.

- **Tarefa**: Ordenar pratos em ordem decrescente de prioridade. Em caso de empate na prioridade, o tempo de preparo é usado como critério secundário (ordem crescente).
- **Condições**:
  - Cada prato tem uma prioridade (\(0 < p < 300000\)) e um tempo de preparo (\(0 < t < 1000\)).
  - Nenhum prato possui a mesma combinação de prioridade e tempo.
  - O nome do prato é uma string única de até 50 caracteres.

---

## **Estrutura de Arquivos**

A estrutura de arquivos do projeto está organizada da seguinte forma:

```
├── data/
│   ├── restaurante_pratos_1k.csv
│   ├── restaurante_pratos_5k.csv
│   ├── restaurante_pratos_10k.csv
│   ├── restaurante_pratos_100k.csv
│   ├── restaurante_pratos_300k.csv
│   └── restaurante_pratos_500k.csv
│
├── doc/
│   ├── Bubble and Quick.pdf          # Enunciado do projeto
│   ├── Notas_de_desenvolvimento.txt  # Observações e notas do autor
│   └── Relatorio.md                  # Relatório final do projeto
│
├── include/
│   └── lista_sequencial.h            # Header file da estrutura de lista sequencial
│
├── main/
│   └── main.c                        # Código principal do programa
│
├── results/
│   ├── Comparacao_de_performance.pdf # Análise comparativa de desempenho
│   ├── resultados_1k.csv
│   ├── resultados_5k.csv
│   ├── resultados_10k.csv
│   ├── resultados_100k.csv
│   ├── resultados_300k.csv
│   ├── resultados_500k.csv
│   └── Sintese_dos_resultados.xlsx   # Consolidação dos resultados
│
├── src/
│   └── lista_sequencial.c            # Implementação das funções de lista sequencial
│
└── README.md                         # Arquivo de documentação principal
```

---

## **Instruções de Uso**

### **Compilação e Execução**

1. Certifique-se de que o compilador GCC está instalado em seu sistema.
2. Compile o programa executando:
   ```bash
   gcc main.c src/lista_sequencial.c -o projeto -I include
   ```
3. Execute o programa:
   ```bash
   ./projeto
   ```

### **Testes**

- Os dados de entrada estão disponíveis na pasta `data/` e foram preparados em diferentes tamanhos (1k, 5k, 10k, 100k, 300k, 500k).
- Os resultados das ordenações e comparações de desempenho serão salvos na pasta `results/`.

---

## **Relatório**

O relatório do projeto, contendo a análise comparativa entre os métodos de ordenação e a explicação sobre a escolha dos pivôs no Quick Sort, pode ser encontrado em:

- [Relatorio.md](doc/Relatorio.md)

---

## **Autor**

Desenvolvido por **Adriano Brandão** como parte de um projeto acadêmico da disciplina de **Estrutura de Dados** (Professor Anderson Paulo Avila Santos - Universidade Estadual de Londrina) para estudar algoritmos de ordenação.
