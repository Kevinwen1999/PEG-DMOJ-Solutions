from sys import stdin
input = stdin.readline
N = int(input())
S = {tuple(sorted(input().split())) for _ in xrange(N)}
print 'No two snowflakes are alike.' if len(S) == N else 'Twin snowflakes found.'
