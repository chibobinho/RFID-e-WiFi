#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "meuSSID";
const char* password = "minhaSenha";

void setup(){

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.println("Esperando conexão");
  }
}
void loop() {
  if(WiFi.status()== WL_CONNECTED {
    HTTPClient http; 

    http.begin("http://jsonplaceholder.typicode.com/users"); // DESTINO DA REQUISIÇÃO!!!
    http.addHeader ("Content-Type", "text/plain"); //CONTENT TYPE

    int httpCode = http.POST("Mensagem do ESP01"); 
    string payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);

    http.end();
  }else{
    Serial.println("Erro na conexão Wifi");
  }
  delay(30000);
}
