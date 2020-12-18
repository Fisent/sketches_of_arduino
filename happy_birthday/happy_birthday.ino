int DELAY = 30;

int B = 246;
int C = 261;
int D = 293;
int E = 329;
int F = 349;
int G = 392;
int A = 440;
int F_sharp = 369;

void nutka(int frequency, int length=1){
  tone(4, frequency);
  delay(DELAY * length);
  noTone(4);
  delay(DELAY);
}

void happy_birthday(){
  nutka(G);
  nutka(G);
  nutka(A);
  nutka(G);
  nutka(C, 2);
  nutka(B);

  delay(1000);

  nutka(G);
  nutka(G);
  nutka(A);
  nutka(G);
  nutka(D, 2);
  nutka(C);

  delay(1000);

  nutka(G);
  nutka(G);
  nutka(G);
  nutka(E);
  nutka(C);
  nutka(B);
  nutka(A, 2);

  delay(1000);

  nutka(F);
  nutka(F);
  nutka(E);
  nutka(C);
  nutka(D);
  nutka(C);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  happy_birthday();
}

void loop() {
  // put your main code here, to run repeatedly:

}
