function ajax(nome, camada) { // nome: texto a ser enviado, camada: id do elemento onde a resposta será exibida
    var url = 'https//httpbin.org/get?text=' + nome;// URL corrigida para incluir o protocolo correto
    var xmlHttp = new XMLHttpRequest();// Criação do objeto XMLHttpRequest
    xmlHttp.onreadystatechange = function() {// Função de callback para processar a resposta
        if (xmlHttp.readyState === 4 && xmlHttp.status === 200) {// Verifica se a requisição foi concluída com sucesso
            var resposta = xmlHttp.responseText;// Obtém a resposta do servidor
            document.getElementById(camada).innerHTML = resposta;// Exibe a resposta no elemento especificado
        }
    }
    xmlHttp.open("GET", url, true);// Configura a requisição HTTP
    xmlHttp.send();// Envia a requisição
}