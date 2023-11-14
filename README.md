# PIM-IV
PIM IV do curso Análise e Desenvolvimento de Sistemas, UNIP 2023

# INTEGRANTES
- 2308454 - Victor Hugo Gagliardi Malaquias
- 2317412 - Lidyane Vitoria Gagliardi Malaquias
- 2318799 - Cainan Henrique Ferreira

# PROBLEMA APRESENTADO
O objetivo do projeto será desenvolver um sistema em C (utilizando o codeblocks – disponível de forma gratuita no seguinte link: http://www.codeblocks.org/) que será utilizado pela START-UP de soluções ambientais
no controle de residuos descartados em rios.

Ao iniciar o sistema a empresa irá se deparar com uma tela de Login.

Feito o Login, o sistema ira redirecionar o usuário para uma tela com 4 opções, sendo:

1 - Registrar uma nova empresa
2 - Atualizar os dados Ambientais
3 - Gerar Relatorios
4 - Sair

Para registrar uma nova empresa o usuario irá precisar dos seguintes dados:

- Nome da empresa,
- Razão social da empresa,
- Nome do responsavel,
- CNPJ da empresa,
- Email da empresa,
- Telefone da empresa,
- Endereço da empresa.

Para Atualizar os dados ambientais o usuario irá precisar passar o nome da Empresa que deseja alterar o dado e incluir também a quantidade de residuo descartado pela mesma.

Para gerar relatório de determinada empresa o usuario irá precisar apenas digitar o nome da empresa que quer consultar.

Todos estes dados serão salvos em um arquivo.txt(a principal vantagem de um arquivo é que as informações armazenadas podem ser consultadas a qualquer momento).

O sistema conta com uma criptografia básica onde apenas o nome da empresa fica visivel no arquivo, os demais dados ficam com as letras embaralhadas seguindo a lógica do código
da criptografia que definimos em nosso código fonte. (Adicionamos o código para descriptografar no Código fonte porem não implementamos em nosso sistema, só deixamos o código lá disponivel 
caso alguém deseja utiliza-lo.)


# INSTRUÇÕES PARA COMPILAÇÃO

1 - Instale o CodeBlocks no seu sistema. Você pode acessar o site oficial da IDE em: http://www.codeblocks.org/ e selecionar o seu sistema operacional.

2 - O código fornecido a cima contem 3 arquivos, sendo eles:

- EmpresaRegistos -> o arquivo.txt onde contem todos os dados salvos
- main -> o código fonte
- SistemaEmpresa -> o sistema console da empresa.

3 - Para abrir o sistema executavel atraver do codigo fonte basta o usuario ir até "Build > Build and Run" e o programa será executado, ou pode estar acessando diretamente o 
SistemaEmpresa.

