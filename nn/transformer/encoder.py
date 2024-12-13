import torch
import copy
import torch.nn as nn
import torch.nn.functional as F

from attention import MultiHeadAttention
from ffn import FFN
from embed import SinusoidalPositionalEncoding, TokenEmbedding


def replicate(m, N=6) -> nn.ModuleList:
    """
    Method to replicate the existing block to N set of blocks
    :param m: class inherited from nn.Module, mainly it is the encoder or decoder part of the architecture
    :param N: the number of stack, in the original paper they used 6
    :return: a set of N blocks
    """
    m_stack = nn.ModuleList([copy.deepcopy(m) for _ in range(N)])
    return m_stack


class Encoder(nn.Module):
    def __init__(self, vocab_size, seq_len, num_heads, d_model, d_ff):
        super(Encoder, self).__init__()
        self.token_embed = TokenEmbedding(vocab_size, d_model)
        self.pos_embed = SinusoidalPositionalEncoding(d_model, seq_len)
