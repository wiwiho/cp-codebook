mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dis(1, 100);
cout << dis(rnd) << "\n";