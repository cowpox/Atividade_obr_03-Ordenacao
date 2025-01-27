# Relatório Comparativo dos Métodos de Ordenação e Escolha de Pivôs no Quicksort

---

## Introdução

Este relatório apresenta uma análise comparativa entre os métodos de ordenação Bubble Sort e Quick Sort, destacando o desempenho de cada algoritmo em diferentes tamanhos de datasets. Também discute a escolha de estratégias para seleção de pivôs no Quick Sort, com base nas implementações realizadas e nos resultados obtidos durante o projeto.

---

## Comparação dos Métodos de Ordenação

Foram implementados e testados três algoritmos:

1. **Bubble Sort**: Ordenação com dois critérios (prioridade e tempo de preparo), de complexidade \(O(n^2)\).
2. **Quick Sort com Pivô à Direita**: Seleção do pivô como o último elemento do array, de complexidade média \(O(n \log n)\).
3. **Quick Sort com Mediana de 3**: Seleção do pivô como a mediana entre o primeiro, o último e o elemento central do array, também de complexidade média \(O(n \log n)\).

Os testes foram realizados com datasets contendo 1k, 5k, 10k, 100k, 300k e 500k registros, cada um testado 10 vezes. As principais observações são:

### **Bubble Sort**

- Foi o algoritmo mais lento em todos os testes, com tempos de execução que aumentaram exponencialmente com o tamanho do dataset.
- Com 500k registros, o Bubble Sort tornou-se impraticável, com um tempo de execução muito superior ao dos demais algoritmos.
- É adequado apenas para fins educacionais ou pequenos volumes de dados.

### **Quick Sort (Pivô à Direita e Mediana de 3)**

- Ambos apresentaram desempenho excelente, com tempos médios muito baixos mesmo para datasets grandes.
- O Quick Sort com Pivô à Direita é simples de implementar e teve um desempenho levemente superior em datasets pequenos.
- O Quick Sort com Mediana de 3 mostrou-se mais robusto em datasets maiores, garantindo partições mais balanceadas e eficiência estável.

### **Comparação Geral**

- O Quick Sort foi consistentemente superior ao Bubble Sort, apresentando tempos de execução dezenas ou centenas de vezes menores.
- A diferença entre as duas estratégias de Quick Sort foi mínima, mas a Mediana de 3 pode ser a melhor escolha para cenários com grandes volumes de dados ou distribuições imprevisíveis.

---

## Escolha dos Pivôs no Quicksort

A escolha do pivô no Quick Sort influencia diretamente a eficiência do algoritmo, especialmente em cenários de grandes volumes de dados. Durante o projeto, foram testadas duas abordagens principais:

### **Pivô à Direita**

- Escolher o último elemento como pivô foi a abordagem inicial, devido à simplicidade de implementação e ao fato de os dados gerados possuírem combinações únicas de prioridade e tempo.
- Embora eficiente em datasets pequenos e moderadamente grandes, pode gerar partições desbalanceadas em dados previamente ordenados, aumentando o risco do pior caso \(O(n^2)\).

### **Mediana de 3**

- Posteriormente, foi implementado o método da Mediana de 3, que seleciona o pivô como a mediana entre o primeiro, o último e o elemento central do array.
- Essa abordagem minimiza o risco de partições desbalanceadas, especialmente em dados parcialmente ordenados ou com padrões específicos.
- Para datasets maiores, a Mediana de 3 apresentou desempenho mais estável, com tempos médios ligeiramente inferiores aos do pivô à direita.

#### **Justificativa Prática**

- A combinação de unicidade dos valores de prioridade e tempo, aliada à distribuição controlada dos dados, garantiu que ambas as abordagens fossem eficientes.
- No entanto, a Mediana de 3 foi preferida em cenários com grandes volumes de dados, devido à sua robustez contra desbalanceamentos e à garantia de partições mais equilibradas.

---

## Conclusão

O projeto demonstrou a clara superioridade do Quick Sort em relação ao Bubble Sort, tanto em termos de desempenho quanto de escalabilidade. Entre as estratégias de pivôs no Quick Sort, a escolha inicial do pivô à direita mostrou-se eficiente em contextos menores, enquanto a Mediana de 3 foi essencial para garantir desempenho consistente em datasets maiores.

Essas escolhas refletem uma abordagem prática e adaptativa, equilibrando simplicidade de implementação e eficiência computacional, o que foi crucial para lidar com os diferentes tamanhos de datasets e suas peculiaridades.

---
