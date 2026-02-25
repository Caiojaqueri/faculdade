const url = 'https://randomuser.me/api/?results=10';// url para buscar usuários aleatórios

async function getUsers(lista){//Funcão assíncrona para buscar usuários
    const resp = await fetch(url);// Faz a requisição para a URL
    const objeto = await resp.jason(); // Converte a resposta em JSON
    let itens = ""; // Variável para armazenar os itens da lista
    for (let pessoa of objeto.results) {// Itera sobre os resultados
        itens += `<li>${pessoa.name.first} ${pessoa.name.last}</li>`;// Adiciona cada nome à lista
    }
    document.getElementById(lista).innerHTML = itens;// Atualiza o conteúdo do elemento com o ID fornecido
}