#include <stdio.h>

void ler_notas_praticas(float P[], int n) {
    float notap_1, notap_2, notap_3;

    for(int i = 0; i < n; i++) {
        scanf("%f %f %f", &notap_1, &notap_2, &notap_3);
        P[i] = (notap_1 + notap_2 + notap_3) / 3;
    }
}

void ler_notas_teoricas(float T[], int n) {
    float notat_1, notat_2;
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &notat_1, &notat_2);
        T[i] = (notat_1 + notat_2) / 2;
    }

}

float encontrar_maximo(float vetor[], int n) {
    int i;
    float maximo = vetor[0];
    for (i = 0; i < n; i++) {
        if (maximo < vetor[i]) {
            maximo = vetor[i];
        }
    }
    return maximo;
}

void multiplicar_fator(float vetor[], int n, float fator) {
    for (int i = 0; i < n; i++) {
        vetor[i] *= fator;
    }
}

float calcular_media_vetor(float vetor[], int n) {
    float media = 0;
    for (int i = 0; i < n; i++) {
        media += vetor[i] / n;
    }
    return media;
}

void calcular_media_final(float P[], float T[], float F[], int n) {
    for (int i = 0; i < n; i++) {
        float media;
        media = (calcular_media_vetor(P, n) + calcular_media_vetor(T, n)) / 2;
        F[i] = media;
    }
}

void imprimir_notas(float F[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.1f\n", F[i]);
    }
}

int main() {
    int n;
    float P[n];
    float T[n];
    float F[n];
    float maximo_t;
    float maximo_p;
    float media_p;
    float media_t;

    scanf("%d", &n);

    ler_notas_praticas(P, n);
    ler_notas_teoricas(T, n);

    multiplicar_fator(P, n, 1.1);

    maximo_t = encontrar_maximo(T, n);
    multiplicar_fator(T, n, 10.0 / maximo_t);

    calcular_media_final(P, T, F, n);

    imprimir_notas(F, n);

    maximo_p = encontrar_maximo(P, n);
    maximo_t = encontrar_maximo(T, n);
    media_p = calcular_media_vetor(P, n);
    media_t = calcular_media_vetor(T, n);

    printf("Max P: %.1f", maximo_p);
    printf("Max T: %.1f", maximo_t);
    printf("Media P: %.1f", media_p);
    printf("Media T: %.1f", media_t);
}