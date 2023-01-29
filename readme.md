# このリポジトリについて
C++で書いたプログラムを32ビットARM向けにクロスコンパイルし、
作成したGoogle Testによる単体テストをGitHub Actionを使って自動化する一例です。

# 要点
- .github/workflows/build.yml

    GitHub Action用のスクリプトのようなものです。
    おおむね、このスクリプト内のコマンドを実行すれば、Ubuntuならローカルでも環境構築が可能です。
    (g++, CMakeあたりは別途必要かもしれませんが)

- toolchain/arm_toolchain.cmake

    クロスコンパイラを指定しています。
    これを指定しなければ、基本的には通常のコンパイルが走ります。

- exec_arm.sh

    QEMUを使ってクロスコンパイルしたバイナリを実行しています。
    GitHub Actionの実行環境はx86_64のUbuntuなので、QEMUを介す必要があります。

- CMakeLists.txt

    これで一番詰まっていました。WSL1の環境だと、Google TestのFetch後、ビルド中にrename failedで失敗します。
    どうにもならなかったので、おとなしくWSL2の環境で対応しました。
    (今からWSLをインストールすれば基本的にデフォルトでWSL2が入るはずです)

# テスト結果について
あえて、必ずFailになる状態にしています。
IA64とARM32の環境差分として、longの最大値の差分で確認できるようにしています。

テストコードはARM32前提で記載しているため、test_native.shはFAILします。