# Level3 : philosophers
## 課題要件
- プログラム名: philo
- 提出ファイル: Makefile, *.h, *.cを `philo/` ディレクトリに配置 
- 引数:  
    - `number_of_philosophers`  哲学者の人数 (=フォークの数)
    - `time_to_die`  死ぬまでの時間 (ms)
    - `time_to_eat`  食事する時間 (ms)
    - `time_to_sleep`  睡眠する時間 (ms)
    - `[optional: number_of_times_each_philosopher_must_eat]` プログラムを終了する食事回数
- 使用可能な外部関数:  
    - `memset`、`printf`、`malloc`、`free`、
    `write`、`usleep`、
    `gettimeofday`、
    `pthread_create`、
    `pthread_detach`、
    `pthread_join`、
    `pthread_mutex_init`、
    `pthread_mutex_destroy`、
    `pthread_mutex_lock`、
    `pthread_mutex_unlock`
    - `Libft`の使用: NG

## 目標
- 哲学者の問題をスレッドとミューテックスを使って実装する。
- 必須部分の具体的なルールは以下の通り:  
• 各哲学者は1つのスレッドを用意する。  
• 各哲学者の間には1本のフォークを用意する。したがって、複数の哲学者がいる場合、各哲学者の左側に1本のフォーク、右側にも1本のフォークがある。もし1人の哲学者しかいない場合、テーブルには1本のフォークしかない。  
• 哲学者がフォークを重複して使用しないようにするため、各フォークの状態を保護するためにそれぞれにミューテックスを使用する。

- プログラムのログについて:  
• 哲学者の状態の変化は、以下のフォーマットで表示されなければいけない:  
◦ `timestamp_in_ms X has taken a fork`  
◦ `timestamp_in_ms X is eating`  
◦ `timestamp_in_ms X is sleeping`  
◦ `timestamp_in_ms X is thinking`  
◦ `timestamp_in_ms X died`  
`timestamp_in_ms` には現在のタイムスタンプ（ミリ秒）を、X には哲学者の番号を置き換える。  
• 表示される状態メッセージは、他のメッセージと混在してはいけない。  
• 哲学者が死んだことを知らせるメッセージは、実際に死んだ時から10ミリ秒以内に表示されなければならない。  
• プログラムにデータ競合があってはいけない。





