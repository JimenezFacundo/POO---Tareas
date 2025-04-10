#include <QApplication>
#include <QInputDialog>
#include <QDebug>
#include <QStringList>

// Eliminar espacios de una frase
QString eliminarEspacios(const QString& frase) {
    QString resultado;
    for (QChar c : frase) {
        if (!c.isSpace()) {
            resultado += c;
        }
    }
    return resultado;
}


void ordenarFrases(QStringList& frases) {
    int n = frases.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (frases[j] > frases[j + 1]) {
                QString temp = frases[j];
                frases[j] = frases[j + 1];
                frases[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QStringList frases;

    for (int i = 0; i < 5; ++i) {
        bool ok;
        QString frase = QInputDialog::getText(nullptr, "Ingresar frase", QString("Frase %1:").arg(i + 1), QLineEdit::Normal, "", &ok);
        if (ok && !frase.isEmpty()) {
            frases.append(frase);
        } else {
            --i; // Reintentar si canceló o no escribió nada
        }
    }

    for (int i = 0; i < frases.size(); ++i) {
        frases[i] = eliminarEspacios(frases[i]);
    }

    ordenarFrases(frases);

    qDebug() << "\nFrases ordenadas (sin espacios):";
    for (const QString& frase : frases) {
        qDebug() << frase;
    }

    return 0;
}
